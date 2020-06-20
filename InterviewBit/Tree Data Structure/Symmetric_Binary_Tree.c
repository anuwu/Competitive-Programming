
int test (treenode* l, treenode* r)
{
    if (l == NULL && r == NULL)
        return 1 ;
    else if (l && r)
    {
        if (l->val == r->val)
            return test (l->left, r->right) && test (l->right, r->left) ;
        else
            return 0 ;
    }
    else
        return 0 ;
}


int isSymmetric(treenode* A) 
{
    return test (A->left, A->right) ;
}
