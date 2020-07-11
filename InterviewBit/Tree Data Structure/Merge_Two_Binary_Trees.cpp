TreeNode* Solution::solve(TreeNode* A, TreeNode* B) 
{
    A->val += B->val ;
    
    if (B->left)
    {
        if (A->left)
            solve (A->left, B->left) ;
        else
            A->left = B->left ;
    }
    
    if (B->right)
    {
        if (A->right)
            solve (A->right, B->right) ;
        else
            A->right = B->right ;
    }
    
    return A ;
}

