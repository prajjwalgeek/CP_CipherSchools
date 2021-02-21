#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

node *addnode(int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = addnode(1);
    root->left = addnode(2);
    root->right = addnode(3);
    root->left->left = addnode(4);
    root->left->right = addnode(5);
    cout << "preorder"
         << "\n";
    preorder(root);
    cout << "\nInorder"
         << "\n";
    inorder(root);
    cout << "\nPostorder"
         << "\n";
    postorder(root);
}