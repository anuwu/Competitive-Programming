int Solution::solve(vector<int> &A, int B) 
{
    int i, len, N = A.size() ;
    long long sum, other ;
    unordered_map<long long, int> m ;
    
    len = INT_MIN ;
    sum = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        sum += A[i] ;
        if (sum == B)
        {
            if (i + 1 > len)
                len = i + 1 ;
        }
        
        other = sum - B ;
        if (m.find (other) != m.end())
        {
            if (i - m[other] > len)
                len = i - m[other] ;
        }
        
        if (m.find (sum) == m.end ())
            m[sum] = i ;
    }
    
    if (len == INT_MIN)
        return -1 ;
    else
        return len ;
}

