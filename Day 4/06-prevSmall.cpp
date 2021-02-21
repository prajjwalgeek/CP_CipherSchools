#include<bits/stdc++.h>
using namespace std;


void PrevSmall(int arr[],int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>arr[i]){
            s.pop();
        }
        if(!s.empty()){
            cout<<s.top()<<" ";
        }
        else{
            cout<<"no small"<<" ";
        }
        s.push(arr[i]);

    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    PrevSmall(arr,n);
}