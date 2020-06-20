int minDepth(treenode* A) 
{
    if (A == NULL)
        return 0 ;
        
    int l, r ;
    l = minDepth (A->left) ;
    r = minDepth (A->right) ;
    
    if (l == 0)
        return r + 1 ;
    if (r == 0)
        return l + 1 ;
}
