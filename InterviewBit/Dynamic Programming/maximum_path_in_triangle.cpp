int Solution::solve(vector<vector<int> > &A) 
{
    int i, j, ans, N = A.size() ;
    vector<vector<int>> dp (N, vector<int> (N, 0)) ;
    
    dp[0][0] = A[0][0] ;
    for (i = 1 ; i < N ; i++)
    {
        dp[i][0] = dp[i-1][0] + A[i][0] ;
        dp[i][i] = dp[i-1][i-1] + A[i][i] ;
        
        for (j = 1 ; j < i ; j++)
            dp[i][j] = max (dp[i-1][j-1], dp[i-1][j]) + A[i][j] ;
    }
    
    ans = dp[N-1][0] ;
    for (j = 1 ; j < N ; j++)
        if (dp[N-1][j] > ans)
            ans = dp[N-1][j] ;
            
    return ans ;
}
