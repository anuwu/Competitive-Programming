Node* ans ;
int height ;
int n1glob, n2glob ;

void lcafinder (Node* root, int h, bool* f1, bool* f2)
{
    if (!root)
        return ;
        
    bool fl1, fl2, fr1, fr2 ;
    fl1 = fl2 = fr1 = fr2 = false ;
    if (root->data == n1glob)
        *f1 = true ;
    if (root->data == n2glob)
        *f2 = true ;

    lcafinder (root->left, h + 1, &fl1, &fl2) ;
    lcafinder (root->right, h + 1, &fr1, &fr2) ;

    if (!(*f1))
        *f1 = fl1 || fr1 ;
    if (!(*f2))
        *f2 = fl2 || fr2 ;
        
    if (*f1 && *f2 && h > height)
    {
        height = h ;
        ans = root ;
    }
}


Node* lca(Node* root ,int n1 ,int n2)
{
    ans = NULL ;
    n1glob = n1 ;
    n2glob = n2 ;
    height = INT_MIN ;
    
    bool f1root, f2root ;
    f1root = f2root = false ;
    
    lcafinder (root, 0, &f1root, &f2root) ;
    
    return ans ;
}