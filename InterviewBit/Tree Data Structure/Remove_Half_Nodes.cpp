TreeNode* Solution::solve(TreeNode* root) 
{
    if (!root)
        return NULL ;
        
    if (!root->left && !root->right)
        ;
    else if (root->left && root->right)
    {
        root->left = solve (root->left) ;
        root->right = solve (root->right) ;
    }
    else if (root->left)
        root = solve (root->left) ;
    else
        root = solve (root->right) ;
        
    return root ;
}

