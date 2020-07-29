int Solution::minDistance(string s1, string s2) 
{
    int i, j, M = s1.length (), N = s2.length () ;
    vector<vector<int>> dp (M+1, vector<int> (N+1, 0)) ;
    
    dp[0][0] = 0 ;
    for (j = 0 ; j < N ; j++)
        dp[0][j+1] = j+1 ;
        
    for (i = 0 ; i < M ; i++)
        dp[i+1][0] = i+1 ;
        
    for (i = 0 ; i < M ; i++)
    {
        for (j = 0 ; j < N ; j++)
        {
            if (s1[i] == s2[j])
                dp[i+1][j+1] = dp[i][j] ;
            else
                dp[i+1][j+1] = min (dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1 ; 
        }
    }
    
    return dp[M][N] ;
}

