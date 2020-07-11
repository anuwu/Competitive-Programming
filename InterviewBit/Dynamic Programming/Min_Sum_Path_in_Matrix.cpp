int Solution::minPathSum(vector<vector<int>> &A) 
{
    int i, j, R = A.size(), C = A[0].size() ;
    vector<vector<int>> dp (R, vector<int> (C, 0)) ;
    
    dp[0][0] = A[0][0] ;
    for (j = 1 ; j < C ; j++)
        dp[0][j] = dp[0][j-1] + A[0][j] ;
        
    for (i = 1 ; i < R ; i++)
    {
        dp[i][0] = dp[i-1][0] + A[i][0] ;
        for (j = 1 ; j < C ; j++)
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + A[i][j] ;
    }
    
    return dp[R-1][C-1] ;
}

