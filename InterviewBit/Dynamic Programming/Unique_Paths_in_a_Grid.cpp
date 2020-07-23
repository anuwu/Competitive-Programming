int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) 
{
    int i, j, N = A.size(), M = A[0].size() ;
    vector<vector<int>> dp (N, vector<int> (M, 0)) ;
    
    for (i = 0 ; i < N ; i++)
    {
        if (A[i][0] == 1)
            break ;
        dp[i][0] = 1 ;
    }
    
    for ( ; i < N ; i++)
        dp[i][0] = 0 ;
            
            
    for (j = 0 ; j < M ; j++)
    {
        if (A[0][j] == 1)
            break ; 
        dp[0][j] = 1 ;
    }      
    
    for ( ; j < M ; j++)
        dp[0][j] = 0 ;
    
    for (i = 1 ; i < N ; i++)
    {
        for (j = 1 ; j < M ; j++)
        {
            if (A[i][j] == 1)
                dp[i][j] = 0 ;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
        }
    }
    
    return dp[N-1][M-1] ;
}

