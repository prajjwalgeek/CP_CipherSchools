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

int BST(node *node, int min, int max)
{
    if (node == NULL)
        return 1;

    if (node->data < min || node->data > max)
        return 0;

    return BST(node->left, min, node->data - 1) &&
           BST(node->right, node->data + 1, max);
}

int IsBst(node *node)
{
    return (BST(node, 0, 0));
}

int main()
{
    node *root = addnode(1);
    root->left = addnode(2);
    root->right = addnode(3);
    root->left->left = addnode(4);
    root->left->right = addnode(5);
    cout << IsBst(root);
}