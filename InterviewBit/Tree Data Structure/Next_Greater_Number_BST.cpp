TreeNode* Solution::getSuccessor(TreeNode* A, int B) 
{
    TreeNode *lastleft, *tmp ;
    
    lastleft = NULL ;
    tmp = A ;
    while (true)
    {
        if (tmp->val == B)
            break ;
        
        if (B > tmp->val)
            tmp = tmp->right ;
        else
        {
            lastleft = tmp ;
            tmp = tmp->left ;
        }
    }
    
    if (tmp->right)
    {
        tmp = tmp->right ;
        while (tmp->left)
            tmp = tmp->left ;
    }
    else
        tmp = lastleft ;
        
    return tmp ;
}
