vector<int> Solution::solve(vector<int> &A) 
{
    int i, ind, N = A.size() ;
    unordered_map<int,int> m ;
    
    for (i = 0 ; i < N ; i++)
    {
        if (m.find(A[i]) == m.end())
            m[A[i]] = i ;
        else
        {
            ind = m[A[i]] ;
            A[ind]++ ;
            if (m.find(A[ind]) == m.end() || ind < m[A[ind]])
                m[A[ind]] = ind ;
                
            m[A[i]] = i ;
        }
    }
    
    return A ;
}

