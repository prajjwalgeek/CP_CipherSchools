#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

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

int Sum(node *root, int result)
{
    if (root == NULL)
    {
        return 0;
    }
    int curr = root->data + (Sum(root->left, result)) + (Sum(root->right, result));
    result = max(result, curr);
    return result;
}

int SumLargest(node *root)
{
    int ans = -1000;
    ans = Sum(root, ans);
    return ans;
}

int main()
{
    node *root = addnode(1);
    root->left = addnode(2);
    root->right = addnode(3);
    root->left->left = addnode(4);
    root->left->right = addnode(5);
    cout << SumLargest(root);
    return 0;
}