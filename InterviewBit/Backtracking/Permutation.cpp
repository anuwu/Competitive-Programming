
void permutations (int indst, vector<int> &A, vector<int> sub, vector<int> mask, vector<vector<int>> &ans)
{
    if (indst == -1)
    {
        ans.push_back (sub) ;
        return ;
    }
    
    int i, prevind, indstst ;
    vector<int>::iterator it ;
    
    i = indst + 1 ;
    while (i < A.size() && mask[i])
        i++ ;
        
    if (i == A.size())
        indstst = -1 ;
    else
        indstst = i ;
        
    mask[indst] = 1 ;
    sub.push_back (A[indst]) ;
    permutations (indstst, A, sub, mask, ans) ;
    it = sub.end() - 1 ;
    sub.erase (it) ;
    prevind = indst ;
    
    for ( ; i < A.size() ; i++)
    {
        if (!mask[i])
        {
            mask[prevind] = 0 ;
            mask[i] = 1 ;
            sub.push_back (A[i]) ;
            permutations (indst, A, sub, mask, ans) ;
            it = sub.end() - 1 ;
            sub.erase (it) ;
            prevind = i ;
        }
    }
}

vector<vector<int>> Solution::permute(vector<int> &A) 
{
    sort (A.begin(), A.end()) ;
    
    vector<int> sub, mask (A.size (), 0) ;
    vector<vector<int>> ans ;
    
    if (A.size())
        permutations (0, A, sub, mask, ans) ;
    
    return ans ;
}

