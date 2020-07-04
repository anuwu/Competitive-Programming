Node *ancstr ;

bool lcafinder (Node *root, int n1, int n2, bool f1, bool f2)
{
    if (root == NULL)
        return false ;
    
    bool find1, find1 ;
    find1 = find2 = false ;
    
    if (!f1 && root->data == n1)
    {
        find1 = true ;
        find2 = lcafinder (root->left, n1, n2, true, false) || lcafinder (root->right, n1, n2, true, false) ;
    }
    
    if (!f2 && root->data == n2)
    {
        find1 = lcafinder (root->left, n1, n2) || lcafinder (root->right, n1, n2) ;
    }
        
}



Node* lca(Node* root ,int n1 ,int n2 )
{
    
}
