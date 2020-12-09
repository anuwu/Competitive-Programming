Node *lca(Node *root, int v1, int v2) 
{
    if (!root)
        return NULL ;
        
    int small, large ;
    small = min(v1, v2) ;
    large = max(v1, v2) ;
    
    if (root->data < small)
        return lca(root->right, v1, v2) ;
    else if (root->data > large)
        return lca(root->left, v1, v2) ;
    else
        return root ;
}
