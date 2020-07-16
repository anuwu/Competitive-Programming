int Solution::solve(vector<vector<int> > &A) 
{
    int i, j, N = A.size() ;
    vector<vector<int>> dp (N, vector<int> (3, 0)) ;
    
    dp[0] = A[0] ;
    for (i = 1 ; i < N ; i++)
    {
        dp[i][0] = min (dp[i-1][1], dp[i-1][2]) + A[i][0] ;
        dp[i][1] = min (dp[i-1][0], dp[i-1][2]) + A[i][1] ;
        dp[i][2] = min (dp[i-1][0], dp[i-1][1]) + A[i][2] ;
    }
    
    return min (dp[N-1][0], min (dp[N-1][1], dp[N-1][2])) ;
}

