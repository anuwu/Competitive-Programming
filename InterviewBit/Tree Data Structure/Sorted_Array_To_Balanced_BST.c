void insert (treenode* root, int l, int r, const int* A)
{
    if (l > r)
        return NULL ;
    
    int mid ;
    mid = (l + r)/2 ;
    if (A[mid] > root->val)
    {
        root->right = treenode_new (A[mid]) ;
        root = root->right ;
    }
    else if (A[mid] < root->val)
    {
        root->left = treenode_new (A[mid]) ;
        root = root->left ;
    }
    
    insert (root, l, mid - 1, A) ;
    insert (root, mid + 1, r, A) ;
}
 
treenode* sortedArrayToBST(const int* A, int n1) 
{
    treenode *root = treenode_new (A[n1/2]) ;
    treenode *tmp ;
    
    insert (root, 0, n1/2 - 1, A) ;
    insert (root, n1/2 + 1, n1 - 1, A) ;
    
    return root ;
}
