//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

class Solution {
private:TreeNode *lca(TreeNode * root,int n1,int n2)
{ 
    if (root == NULL) return NULL; 
    if (root->val > n1 && root->val > n2) 
        return lca(root->left, n1, n2); 
    if (root->val < n1 && root->val < n2) 
        return lca(root->right, n1, n2); 
    return root; 
} 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return lca(root,p->val,q->val);         
    }
};
