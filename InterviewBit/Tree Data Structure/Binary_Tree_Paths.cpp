vector<vector<int>> leavesPath ; 

void leafPath (TreeNode *root, vector<int> path)
{
    path.push_back (root->val) ;
    
    if (!root->left && !root->right)
    {
        leavesPath.push_back (path) ;
        return ;
    }
    
    if (root->left)
        leafPath (root->left, path) ;
    if (root->right)
        leafPath (root->right, path) ;
}
 
vector<vector<int>> Solution::solve(TreeNode* A) 
{
    leavesPath.clear () ;
    
    vector<int> path ;
    leafPath (A, path) ;
    
    return leavesPath ;
}


