#include <bits/stdc++.h>
using namespace std;

#define max 2000
struct node
{
    int data;
    node *left, *right;
};

struct node *addnode(int val)
{
    struct node *newnode = new node();
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void PrintPath(node *node, int arr[], int n)
{
    if (node == NULL)
        return;

    arr[n] = node->data;
    n++;

    if (node->left == NULL && node->right == NULL)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        PrintPath(node->left, arr, n);
        PrintPath(node->right, arr, n);
    }
}

void solve(node *node)
{
    int path[max];
    PrintPath(node, path, 0);
}

int main()
{
    node *root = addnode(1);
    root->left = addnode(2);
    root->right = addnode(3);
    root->left->left = addnode(4);
    root->left->right = addnode(5);
    solve(root);
    return 0;
}