
int bstval (TreeNode* node, int leftlim, int rightlim)
{
    if (node == NULL)
        return 1 ;
    
    if (node->val >= leftlim && node->val < rightlim)
        return bstval (node->left, leftlim, node->val) && bstval (node->right, node->val, rightlim) ;
    else
        return 0 ;
}

int Solution::isValidBST(TreeNode* A) 
{
    return bstval (A->left, INT_MIN, A->val) && bstval (A->right, A->val, INT_MAX) ;
}
