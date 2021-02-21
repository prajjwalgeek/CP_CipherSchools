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

int mirror(node *head1, node *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return true;
    }
    if (head1 == NULL || head2 == NULL)
    {
        return false;
    }
    return (head1->data == head2->data && mirror(head1->left, head2->right) && mirror(head1->right, head2->left));
}

int main()
{
    node *root = addnode(1);
    root->left = addnode(2);
    root->right = addnode(3);
    // root->left->left=addnode(4);
    // root->left->right=addnode(5);

    node *root1 = addnode(1);
    root1->left = addnode(3);
    root1->right = addnode(2);
    // root1->left->left=addnode(4);
    // root1->left->right=addnode(5);

    cout << mirror(root, root1);
}