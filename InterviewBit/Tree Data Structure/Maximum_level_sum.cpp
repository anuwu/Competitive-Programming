int Solution::solve(TreeNode* A) 
{
    int i, sum, max ;
    vector<TreeNode*> lev, nexlev ;
    
    max = INT_MIN ;
    nexlev.push_back (A) ;
    do
    {
        lev = nexlev ;
        nexlev.clear () ;
        sum = 0 ;
        for (i = 0 ; i < lev.size() ; i++)
        {
            sum += lev[i]->val ;
            if (lev[i]->left)
                nexlev.push_back (lev[i]->left) ;
            if (lev[i]->right)
                nexlev.push_back (lev[i]->right) ;
        }
        
        if (sum > max)
            max = sum ;
    } while (nexlev.size()) ;
    
    return max ;
}

