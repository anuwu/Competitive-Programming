int n1, n2, lcaHeight ;
int lcaVal ;

void lcaFinder (TreeNode* root, int h, bool* f1, bool* f2)
{
    if (!root)
        return ;
        
    if (root->val == n1)
        *f1 = true ;
    if (root->val == n2)
        *f2 = true ;
        
    bool l1, l2, r1, r2 ;
    l1 = l2 = r1 = r2 = false ;
    
    lcaFinder (root->left, h+1, &l1, &l2) ;
    lcaFinder (root->right, h+1, &r1, &r2) ;
    
    *f1 = *f1 || l1 || r1 ;
    *f2 = *f2 || l2 || r2 ;
    
    if (*f1 && *f2 && h > lcaHeight)
    {
        lcaVal = root->val ;
        lcaHeight = h ;
    }
}

int Solution::lca(TreeNode* A, int B, int C) 
{
    n1 = B ;
    n2 = C ;
    lcaHeight = INT_MIN ;
    lcaVal = -1 ;
    
    bool f1root, f2root ;
    f1root = f2root = false ;
    lcaFinder (A, 0, &f1root, &f2root) ;
    
    return lcaVal ;
}

