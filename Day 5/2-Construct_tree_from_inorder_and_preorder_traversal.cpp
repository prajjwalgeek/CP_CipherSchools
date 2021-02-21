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

node *helper(int In[], int Pre[], int InS, int InE, int PreS, int PreE)
{
    if (InS > InE)
    {
        return NULL;
    }
    int RootIndex = -1;
    int RootData = Pre[PreS];
    for (int i = InS; i <= InE; i++)
    {
        if (In[i] == RootData)
        {
            RootIndex = i;
            break;
        }
    }

    int LInS = InS;
    int LPreS = PreS + 1;
    int LInE = RootIndex - 1;
    int LPreE = LInE - LInS + LPreS;
    int RPreS = LPreE + 1;
    int RInS = RootIndex + 1;
    int RInE = InE;
    int RPreE = PreE;
    struct node *root = addnode(RootData);
    root->left = helper(In, Pre, LInS, LInE, LPreS, LPreE);
    root->right = helper(In, Pre, RInS, RInE, RPreS, RPreE);
    return root;
}

node *BuildTree(int In[], int Pre[], int n)
{

    node *Root = helper(In, Pre, 0, n - 1, 0, n - 1);
    cout << "\nInorder of the constructed tree is "
         << " ";
    inorder(Root);
    cout << "\nPreorder of the constructed tree is "
         << " ";
    preorder(Root);
    return Root;
}

int main()
{
    int In[] = {4, 2, 5, 1, 3};
    int Pre[] = {1, 2, 4, 5, 3};
    BuildTree(In, Pre, 5);
}