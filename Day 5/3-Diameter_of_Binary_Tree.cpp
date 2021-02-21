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

int height(node *root, int result)
{
    if (root == NULL)
    {
        return 0;
    }
    int Hleft = height(root->left, result);
    int Hright = height(root->right, result);
    result = max(result, 1 + Hleft + Hright);
    int a = max(Hleft, Hright);
    a = a + 1;
    return a;
}
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int result = 0;
    height(root, result);
    return result;
}

int main()
{
    node *root = addnode(1);
    root->left = addnode(2);
    root->right = addnode(3);
    root->left->left = addnode(4);
    root->left->right = addnode(5);
    cout << diameter(root);
}