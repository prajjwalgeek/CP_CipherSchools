#include<bits/stdc++.h>
using namespace std;


bool duplicate(string str,int n)
{
  stack<char> s;
  for(int i=0;i<n;i++){
      if (str[i]==')')
      {
          char top=s.top();
          s.pop();
          int count=0;
          while(top!='('){
              count++;
              top=s.top();
              s.pop();
          }
          if (count<1){
              return true;
          }
      }
      else{
      s.push(str[i]);
      }
  }
  return true;
}

int main(){
    string s="(a+b)";
    int n=s.length();
    cout<<duplicate(s,n);
}