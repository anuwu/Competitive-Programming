int Solution::solve(vector<int> &A, int B) 
{
    int i, xorsum, cnt, N = A.size() ;
    unordered_map<int,int> m ;
    
    xorsum = A[0] ;
    for (i = 1 ; i < N ; i++)
    {
        A[i] = xorsum ^ A[i] ;
        xorsum = A[i] ;
    }
        
    cnt = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] == B)
            cnt++ ;
        
        if (m.find (B ^ A[i]) != m.end())
            cnt += m[B ^ A[i]] ;
            
        if (m.find (A[i]) == m.end())
            m[A[i]] = 1 ;
        else
            m[A[i]]++ ;
    }
    
    return cnt ;
}

