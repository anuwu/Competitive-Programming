
long long path (TreeNode* root, long long pathsum)
{
    if (!root)
        return 0 ;
    else if (!root->left && !root->right)
    {
        pathsum = pathsum*10 + root->val ;
        
        printf ("%ld ", pathsum) ;
        return pathsum ;
    }
    
    long long l, r ;
    pathsum = pathsum * 10 + root->val ;
    l = path (root->left, pathsum) ;
    r = path (root->right, pathsum) ;
    
    return (l % 1003 + r % 1003) % 1003 ;
} 


int Solution::sumNumbers(TreeNode* A) 
{
    return path(A, 0) % 1003 ;
}
