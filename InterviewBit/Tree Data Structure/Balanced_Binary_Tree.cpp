int maxDepth (TreeNode *root)
{
    if (!root) return 0 ;
    
    int l, r ;
    
    l = maxDepth (root->left) ;
    r = maxDepth (root->right) ;
    
    if (l == -1 || r == -1)
        return -1 ;
    else
    {
        if (l - r > 1 || r - l > 1)
            return -1 ;
        else if (l > r)
            return l+1 ;
        else
            return r+1 ;
    }
}

int Solution::isBalanced(TreeNode* A) 
{
    if (maxDepth (A) == -1)
        return 0 ;
    else
        return 1 ;
}
