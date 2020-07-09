int Solution::solve(vector<vector<int> > &A) 
{
    int i, j, ans, N = A.size(), M = A[0].size() ;
    int pleft, pup ;
    bool rowPath ;
    vector<vector<int>> dp (N, vector<int> (M , -1)) ;
    
    ans = -1 ;
    dp[0][0] = 1 ;
    
    for (j = 1 ; j < M ; j++)
    {
        if (A[0][j] > A[0][j-1] && dp[0][j-1] != -1)
        {
            dp[0][j] = dp[0][j-1] + 1 ;
            if (dp[0][j] > ans)
                ans = dp[0][j] ;
        }
    }
    
    for (i = 1 ; i < N ; i++)
    {
        rowPath = false ;
        if (A[i][0] > A[i-1][0] && dp[i-1][0] != -1)
        {
            dp[i][0] = dp[i-1][0] + 1 ;
            rowPath = true ;
        }
        
        for (j = 1 ; j < M ; j++)
        {
            pleft = pup = -1 ;
            if (A[i][j] > A[i][j-1] && dp[i][j-1] != -1)
                pleft = dp[i][j-1] + 1 ;
            if (A[i][j] > A[i-1][j] && dp[i-1][j] != -1)
                pup = dp[i-1][j] + 1 ;
                
            if (pleft > 0 || pup > 0)
            {
                if (pleft > pup)
                    dp[i][j] = pleft ;
                else
                    dp[i][j] = pup ;
                    
                if (dp[i][j] > ans)
                    ans = dp[i][j] ;
                    
                rowPath = true ;    
            }
        }
        
        if (!rowPath)
            break ;
    }
    
    if (dp[N-1][M-1] == -1)
        return -1 ;
    else
        return N + M -1 ;
}

