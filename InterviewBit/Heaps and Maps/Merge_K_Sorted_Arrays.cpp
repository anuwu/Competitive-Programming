vector<int> Solution::solve(vector<vector<int> > &A) 
{
    int i, k, K = A.size(), N = A[0].size() ;
    vector<int> indices (K, 0) ;
    vector<int> ans ;
    multimap<int,int> m ;
    multimap<int,int>::iterator it ;
    
    for (i = 0 ; i < K ; i++)
        m.insert (make_pair (A[i][0], i)) ;
        
    for (k = 0 ; k < N*K ; k++)
    {
        it = m.begin () ;
        ans.push_back (it->first) ;
        i = it->second ;
        m.erase (it) ;
        
        indices[i]++ ;
        if (indices[i] < N)
            m.insert (make_pair (A[i][indices[i]], i)) ;
    }
    
    return ans ;
}

