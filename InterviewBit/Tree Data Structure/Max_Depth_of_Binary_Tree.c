int l, r ;

int maxDepth(treenode* A) {
    if (A == NULL)
        return 0 ;
    
    l = maxDepth (A->left) ;
    r = maxDepth (A->right) ;
    
    if (l > r)
        return l + 1 ;
    else
        return r + 1 ;
}
