int Solution::solve(vector<int> &val, vector<int> &wt, int W) 
{
    int i, j, N = val.size () ;
    vector<vector<int>> dp (N+1, vector<int> (W+1, 0)) ;
    
    for (i = 1 ; i <= N ; i++)
    {
        for (j = 1 ; j <= W ; j++)
        {
            if (wt[i-1] <= j)
                dp[i][j] = max (dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]) ;
            else
                dp[i][j] = dp[i-1][j] ;
        }
    }
    
    return dp[N][W] ;
}
