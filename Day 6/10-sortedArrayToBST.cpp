#include<bits/stdc++.h> 
using namespace std; 

class Node 
{ 
	public: 
	int data; 
	Node* left; 
	Node* right; 
}; 

Node * newNode(int data); 

Node* sortedArrayToBST(int arr[],int start, int end) 
{ 
	if (start > end) 
	return NULL; 
	int mid = (start + end)/2; 
	Node *root = newNode(arr[mid]); 
	root->left = sortedArrayToBST(arr, start, mid - 1); 
	root->right = sortedArrayToBST(arr, mid + 1, end); 
	return root; 
} 
Node* newNode(int data) 
{ 
	Node* node = new Node(); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
} 


int main() 
{ 
	int n;
    cin>>n; 
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
	Node *root = sortedArrayToBST(arr, 0, n-1); 
	return 0; 
} 


