int sol (TreeNode *root, int sum)
{
    if (!root)
        return 0 ;
    if (root && !root->left && !root->right)
    {
        if (sum == root->val) return 1 ;
        else return 0 ;
    }
    else if (sum < 0) return 0 ;
    
    return sol (root->left, sum - root->val) || sol (root->right, sum - root->val) ;
}

int Solution::hasPathSum(TreeNode* A, int B) 
{
    return sol (A, B) ;
}
