class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* middle=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            middle=middle->next;
            fast=fast->next->next;
        }
        middle->next=reverseList(middle->next);
        middle=middle->next;
        while(middle!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            middle=middle->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};