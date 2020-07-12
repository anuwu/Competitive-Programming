vector<int> Solution::solve(TreeNode* A, int B) 
{
    int i, j ;
    bool breaklev ;
    vector<TreeNode*> lev, nextlev ;
    vector<int> ans ;
    
    if (A->val == B)
        return ans ;
     
    breaklev = false ;   
    nextlev.push_back (A) ;    
    do
    {
        lev = nextlev ;
        nextlev.clear () ;
        for (i = 0 ; i < lev.size() ; i++)
        {
            if ((lev[i]->left && lev[i]->left->val == B) || (lev[i]->right && lev[i]->right->val == B))
            {
                breaklev = true ;
                continue ;
            }
            else
            {
                if (lev[i]->left)
                    nextlev.push_back (lev[i]->left) ;
                if (lev[i]->right)
                    nextlev.push_back (lev[i]->right) ;
            }
        }
        
        if (breaklev)
            break ;
    } while (true) ;
    
    for (i = 0 ; i < nextlev.size() ; i++)
        ans.push_back (nextlev[i]->val) ;
        
    return ans ;
}

