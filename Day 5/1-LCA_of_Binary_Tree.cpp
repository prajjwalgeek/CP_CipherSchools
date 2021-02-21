#include <bits/stdc++.h>
using namespace std;

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

node *utility(node *root, int x, int y, bool &v1, bool &v2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == x)
    {
        v1 = true;
        return root;
    }
    if (root->data == y)
    {
        v2 = true;
        return root;
    }

    node *LeftLca = utility(root->left, x, y, v1, v2);
    node *RightLca = utility(root->right, x, y, v1, v2);

    if (LeftLca != NULL && RightLca != NULL)
    {
        return root;
    }
    if (RightLca != NULL)
    {
        return RightLca;
    }
    else
    {
        return LeftLca;
    }
}
bool search(node *root, int k)
{
    if (root == NULL)
        return false;

    if (root->data == k || search(root->left, k) || search(root->right, k))
        return true;

    return false;
}

node *FindLca(node *root, int n1, int n2)
{
    bool v1 = false, v2 = false;

    node *lca = utility(root, n1, n2, v1, v2);

    if ((v1 != false && v2 != false) || (v1 != false && search(lca, n2)) || (v2 != false && search(lca, n1)))
    {
        return lca;
    }

    return NULL;
}

int main()
{
    node *root = addnode(1);
    root->left = addnode(2);
    root->right = addnode(3);
    root->left->left = addnode(4);
    root->left->right = addnode(5);
    node *Lca = FindLca(root, 4, 3);
    if (Lca != NULL)
    {
        cout << Lca->data;
    }
    else
    {
        cout << "Not present";
    }
}