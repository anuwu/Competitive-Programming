int Solution::solve(vector<int> &A) 
{
    int i, j, sum, halfsum, N = A.size() ;
    
    sum = 0 ;
    for (i = 0 ; i < N ; i++)
        sum += A[i] ;
        
    halfsum = sum/2 ;
    vector<vector<bool>> dp (2, vector<bool> (halfsum+1, false)) ;
    
    dp[0][0] = true ;
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; j <= halfsum ; j++)
            dp[1][j] = dp[0][j] || ((A[i] <= j) ? dp[0][j - A[i]] : false) ;
            
        dp[0] = dp[1] ;
    }
    
    for (i = halfsum ; i >= 0 ; i--)
    {
        if (dp[0][i])
            break ;
    }

    return sum - 2*i ;
}

