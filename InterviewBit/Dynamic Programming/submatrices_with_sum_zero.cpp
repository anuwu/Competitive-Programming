int zeroPairs (vector<int> &A)
{
    int i, pairs = 0, M = A.size() ;
    unordered_map<int,int> m ;
    unordered_map<int,int>::iterator it ;
    
    for (i = 0 ; i < M ; i++)
    {
        if (m.find (A[i]) == m.end ())
            m[A[i]] = 1 ;
        else
            m[A[i]]++ ;
    }
    
    for (it = m.begin () ; it != m.end () ; it++)
    {
        if (it->first == 0)
            pairs += (it->second * (it->second + 1))/2 ;
        else if (it->second > 1)
            pairs += (it->second * (it->second - 1))/2 ;
    }
    
    return pairs ;
}

int Solution::solve(vector<vector<int> > &A) 
{
    if (A.size() == 0)
        return 0 ;
        
    int i, j, rows, sum, total, N = A.size(), M = A[0].size() ;
    
    for (i = 0 ; i < N ; i++)
    {
        sum = A[i][0] ;
        for (j = 1 ; j < M ; j++)
        {
            sum += A[i][j] ;
            A[i][j] = sum ;
        }
    }
    
    vector<vector<int>> dp (N-1, vector<int> (M, 1)) ;
    vector<int> lastrow (M, 0) ;
    
    total = 0 ;
    for (i = 0 ; i < N - 1 ; i++)
    {
        dp[i] = A[i] ;
        total += zeroPairs (dp[i]) ;
    }
    total += zeroPairs (A[N-1]) ;
    
    for (rows = 2 ; rows <= N ; rows++)
    {
        for (j = 0 ; j < M ; j++)
            lastrow[j] = dp[N-2][j] + A[N-1][j] ;
        
        total += zeroPairs (lastrow) ;
        for (i = N-2 ; i >= rows - 1 ; i--)
        {
            for (j = 0 ; j < M ; j++)
                dp[i][j] = dp[i-1][j] + A[i][j] ;
                
            total += zeroPairs (dp[i]) ;
        }
    }
    
    return total ;
}

