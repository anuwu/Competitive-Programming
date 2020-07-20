int Solution::solve(vector<int> &A) 
{
    int i, j, k, l, sum, cost, mincost, N = A.size() ;
    vector<vector<int>> dp (N, vector<int> (N, 0)) ;
    
    sum = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        sum += A[i] ;
        A[i] = sum ;
    }
    
    for (l = 2 ; l <= N ; l++)
    {
        for (i = 0 ; i <= N - l ; i++)
        {
            j = i + l - 1 ;
            mincost = INT_MAX ;
            for (k = i ; k < j ; k++)
            {
                cost = dp[i][k] + dp[k+1][j] + (A[k] - (i == 0 ? 0 : A[i-1])) + (A[j] - A[k]) ;
                if (cost < mincost)
                    mincost = cost ;
            }
            
            dp[i][j] = mincost ;
        }
    }
    
    return dp[0][N-1] ;
}

