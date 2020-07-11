vector<int> Solution::solve(TreeNode* A) 
{
    int i, j, height ;
    TreeNode* tmp ;
    vector<TreeNode*> lev, nextlev ;
    vector<vector<int>> numlevs ;
    vector<int> numlev ;
    
    nextlev.push_back (A) ;
    do
    {
        lev = nextlev ;
        numlev.clear () ;
        for (i = 0 ; i < lev.size() ; i++)
            numlev.push_back (lev[i]->val) ;
        numlevs.push_back (numlev) ;
        
        nextlev.clear () ;
        for (i = 0 ; i < lev.size() ; i++)
        {
            if (lev[i]->left)
                nextlev.push_back (lev[i]->left) ;
            if (lev[i]->right)
                nextlev.push_back (lev[i]->right) ;
        }
    } while (nextlev.size() > 0) ;
    
    numlev.clear () ;
    nextlev.clear () ;
    lev.clear () ;
    
    height = numlevs.size() - 1 ;
    for (i = height - 1 ; i >= 0 ; i--)
    {
        for (j = 0 ; j < numlevs[i].size() ; j++)
            numlevs[height].push_back (numlevs[i][j]) ;
            
        numlevs[i].clear () ;
    }
    
    return numlevs[height] ;
}

