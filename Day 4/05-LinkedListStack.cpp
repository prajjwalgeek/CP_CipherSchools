#include<bits/stdc++.h>
using namespace std;


class Stack{
    public:
    int data;
    Stack* top;

};

Stack* newnode(int Data){
    Stack* new_node=new Stack();
    new_node->data=Data;
    new_node->top=NULL;
    return new_node;
}

int IsEmpty(Stack* head){
    return(head==NULL);
}
Stack* push(Stack* head, int data){
Stack* node=new Stack();
node->data=data;
node->top=head;
head=node;

}

int pop(Stack* head){
    if (IsEmpty(head)){
        return -100000;}
     Stack* temp = head;
    head = head->top;
    int poped_element = temp->data;
    free(temp);
 
    return poped_element;
}
int peak(Stack* node){
  if (IsEmpty(node)){
        return INT_MIN;}
    return node->data;
}

int main()
{
    Stack* head = NULL;
 
    push(head, 1);
    push(head, 2);
    push(head, 3);
 
    cout << pop(head) <<"\n";
 
    cout << peak(head) << endl;
 
    return 0;
}