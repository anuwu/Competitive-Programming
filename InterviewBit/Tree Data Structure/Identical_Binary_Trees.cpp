int Solution::isSameTree(TreeNode* A, TreeNode* B) 
{
    if (!A && !B)
        return 1 ;
    else if (A && B)
        return A->val == B->val && isSameTree (A->left, B->left) && isSameTree (A->right, B->right) ;
    else
        return 0 ;
}
