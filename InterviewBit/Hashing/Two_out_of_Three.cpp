vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    int i ;
    vector<int> ans ;
    unordered_set<int> Aset, Bset, Cset ;
    
    for (i = 0 ; i < A.size() ; i++)
        Aset.insert (A[i]) ;
        
    for (i = 0 ; i < B.size() ; i++)
    {
        if (Aset.find (B[i]) )
        Bset.insert (B[i]) ;
    }
        
    for (i = 0 ; i < C.size() ; i++)
        Cset.insert (C[i]) ;
    
    return ans ;
}

