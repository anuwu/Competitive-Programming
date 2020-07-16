int Solution::solve(vector<int> &A) 
{
    int i, ind, minind, N = A.size() ;
    unordered_map<int,int> m ;
    
    minind = INT_MAX ;
    for (i = 0 ; i < N ; i++)
    {
        if (m.find (A[i]) == m.end ())
            m[A[i]] = i ;
        else
        {
            ind = m[A[i]] ;
            if (ind < minind)
                minind = ind ;
        }
        
    }
    
    if (minind != INT_MAX)
        return A[minind] ;
    else
        return -1 ;
}

