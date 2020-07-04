TreeNode* smallest (TreeNode *root, int B, int *smallCnt)
{
    if (!root)
        return NULL ;
        
    TreeNode *leftres ;
    leftres = smallest (root->left, B, smallCnt) ;
    
    if (leftres)
        return leftres ;
    else
    {
        *smallCnt += 1 ;
        if (*smallCnt == B)
            return root ;
        else
            return smallest (root->right, B, smallCnt) ;
    }
}
 
int Solution::kthsmallest(TreeNode* A, int B) 
{
    int smallCnt = 0 ;
    TreeNode *res ;
    
    res = smallest (A, B, &smallCnt) ;
    if (res)
        return res->val ;
    else
        return -1 ;
}
