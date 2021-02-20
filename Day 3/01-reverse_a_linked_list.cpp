
//Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        
        ListNode *temp = NULL;
        while(head!=NULL)
        {

               ListNode *next = head->next;
               head->next=temp;
               temp=head;
               head=next;
        }
        return temp;
    }
};

//recursive

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* p = reverseList(head->next);
          head->next->next=head;
          head->next= NULL;
          return p; 
}


};
