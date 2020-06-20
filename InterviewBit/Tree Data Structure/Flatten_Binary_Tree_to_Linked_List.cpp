TreeNode* flatt (TreeNode *root, TreeNode *tail)
{
    if (root == NULL)
        return tail ;

    TreeNode *tmp ;
    
    tmp = root->right ;
    tail->right = root ;
    tail = flatt (root->left, root) ;
    root->left = NULL ;
    return flatt (tmp, tail) ;
}

TreeNode* Solution::flatten(TreeNode* A) 
{
    TreeNode *tmp, *tail ;
    
    tmp = A->right ;
    tail = flatt (A->left, A) ;
    A->left = NULL ;
    flatt (tmp, tail) ;

    return A ;
}