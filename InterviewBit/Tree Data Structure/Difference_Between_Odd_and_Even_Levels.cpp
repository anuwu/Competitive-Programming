int Solution::solve(TreeNode* A) 
{
    int i, j, oddsum, evensum ;
    bool even ;
    vector<TreeNode*> lev, nextlev ;
    
    even = false ;
    oddsum = 0 ;
    evensum = 0 ;
    nextlev.push_back (A) ;
    do
    {
        lev = nextlev ;
        nextlev.clear() ;
        for (i = 0 ; i < lev.size() ; i++)
        {
            if (even)
                evensum += lev[i]->val ;
            else
                oddsum += lev[i]->val ;
            
            if (lev[i]->left)
                nextlev.push_back (lev[i]->left) ;
            if (lev[i]->right)
                nextlev.push_back (lev[i]->right) ;
        }
        
        even = !even ;
    } while (nextlev.size() > 0) ;
    
    return oddsum - evensum ;
}

