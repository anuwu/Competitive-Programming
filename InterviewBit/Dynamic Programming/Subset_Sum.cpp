int Solution::solve(vector<int> &A, int B) 
{
    int i, j, N = A.size() ;
    vector<vector<bool>> dp (2, vector<bool> (B+1, false)) ;
    
    
    dp[0][0] = true ;
    dp[1][0] = true ;
    for (i = 1 ; i < N ; i++)
    {
        for (j = 1 ; j <= B ; j++)
            dp[1][j] = dp[0][j] || (A[i] <= j ? dp[0][j - A[i]] : false) ;
            
        dp[0] = dp[1] ;
    }

    return dp[1][B] ;
}
