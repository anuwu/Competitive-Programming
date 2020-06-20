treenode *tmp ;

treenode* invertTree(treenode* A) 
{
    if (A == NULL)
        return NULL ;
        
    tmp = A->left ;
    A->left = A->right ;
    A->right = tmp ;
    
    invertTree (A->left) ;
    invertTree (A->right) ;
    return A ;
}
