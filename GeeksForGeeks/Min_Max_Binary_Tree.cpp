// Returns maximum value in a given Binary Tree
int findMax(struct node* root)
{
    if (!root)
        return INT_MIN ;
        
    int lmin, rmin ;
    lmin = findMax (root->left) ;
    rmin = findMax (root->right) ;
    
    return max (root->data, max (lmin, rmin)) ;
}

// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
    if (!root)
        return INT_MAX ;
        
    int lmin, rmin ;
    lmin = findMin (root->left) ;
    rmin = findMin (root->right) ;
    
    return min (root->data, min (lmin, rmin)) ;
}
