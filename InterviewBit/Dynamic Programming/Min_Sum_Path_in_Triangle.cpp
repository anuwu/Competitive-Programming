int Solution::minimumTotal(vector<vector<int>> &A) 
{
    int i, row, minimum, N = A.size() ;
    vector<int> dp (N, 0), dpnext (N, 0) ;
    
    dp[0] = A[0][0] ;
    for (row = 1 ; row < N-1 ; row++)
    {
        dpnext[0] = dp[0] + A[row][0] ;
        for (i = 1 ; i < row ; i++)
            dpnext[i] = min (dp[i-1], dp[i]) + A[row][i] ;
            
        dpnext[row] = dp[row-1] + A[row][row] ;
        dp = dpnext ;
    }
    
    dpnext[0] = dp[0] + A[N-1][0] ;
    minimum = dpnext[0] ;
    for (i = 1 ; i < N-1 ; i++)
    {
        dpnext[i] = min (dp[i-1], dp[i]) + A[N-1][i] ;
        if (dpnext[i] < minimum)
            minimum = dpnext[i] ;
    }
    
    dpnext[N-1] = dp[N-2] + A[N-1][N-1] ;
    if (minimum > dpnext[N-1])
        minimum = dpnext[N-1] ;
        
    return minimum ;
}

