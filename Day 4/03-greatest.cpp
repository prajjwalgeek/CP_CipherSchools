#include<bits/stdc++.h>
using namespace std;

void nextGretest(int arr[],int n){
    stack<int> s;
    for (int i=0 ;i<n;i++){
        if (s.empty()){
            s.push(arr[i]);
            continue;
        }
        while(!s.empty() && arr[i]>s.top()){
            cout<<arr[i]<<" ";
            s.pop();


        }
        s.push(arr[i]);

    }
    while(!s.empty()==true){
        cout<<"-1"<<" ";
        s.pop();

    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nextGretest(arr,n);

}
