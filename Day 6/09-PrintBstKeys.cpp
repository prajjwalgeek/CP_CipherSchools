//https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range
void Print(Node *root, int k1, int k2,vector<int>&res) 
{ 
    if ( NULL == root ) 
        return; 
    if ( k1 < root->data ) 
        Print(root->left, k1, k2,res); 
    if ( k1 <= root->data && k2 >= root->data ) 
        res.push_back(root->data);
    if ( k2 > root->data ) 
        Print(root->right, k1, k2,res); 
} 
vector<int> printNearNodes(Node *root, int low, int high)
{
  vector<int> result;
  Print(root,low,high,result);
  return result;
}
