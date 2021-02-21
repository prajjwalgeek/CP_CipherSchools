#include<bits/stdc++.h>
using namespace std;


int Stack[100], n=100, top=-1;
void push(int val) {
   if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      Stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< Stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<Stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}

int main() {
   int  val;
   cin>>val;
   push(val);
   display();
  
}