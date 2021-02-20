//if direct node is given this will not work for tail node
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
//if head and data is given
class Solution{
    public:
    void deleteNode(ListNode * head, int data)
    {   if(head==NULL)
        return;
        ListNode * ptr1=head;
        ListNode * ptr2=head->next;
        if(head->val==data)
        {
            head=ptr2;
            delete ptr1;
            return ;
        }
        while(ptr2&&ptr->next)
        {
            if(ptr2->val==data)
            {
                ptr1->next=ptr2->next;
                delete ptr2;
                return ;
            }
            ptr1=ptr2;
            ptr2=ptr2->next;
        }

    }
}