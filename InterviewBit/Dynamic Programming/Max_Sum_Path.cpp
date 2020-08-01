int maxpath (TreeNode *root, int *res)
{
    if (!root)
        return 0 ;
        
    int l, r, maxOne, maxTop ;
    l = maxpath (root->left, res) ;
    r = maxpath (root->right, res) ;
    
    maxOne = max(max(l, r) + root->val, root->val) ;
    maxTop = max(l + r + root->val, root->val) ;
    
    *res = max (*res, maxTop) ;
    return maxOne ;
}
 
 
int Solution::maxPathSum(TreeNode* A) 
{
    if (!A)
        return 0 ;
        
    int res = INT_MIN ;
    maxpath (A, &res) ;
    
    return res ;
}

