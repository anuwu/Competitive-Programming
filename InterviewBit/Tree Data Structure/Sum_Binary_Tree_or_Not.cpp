
int sumTree (TreeNode *root)
{
    if (!root)
        return 0 ;
    
    if (!root->left && !root->right)
        return root->val ;
        
    int leftSum, rightSum ;
    leftSum = sumTree (root->left) ;
    rightSum = sumTree (root->right) ;
    
    if (leftSum == -1 || rightSum == -1 || leftSum + rightSum != root->val)
        return -1 ;
    else
        return leftSum + rightSum + root->val ;      
}


int Solution::solve(TreeNode* A) 
{
    return sumTree (A) > 0 ? 1 : 0 ;
}

