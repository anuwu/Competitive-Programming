int Solution::solve(vector<vector<int> > &A) 
{
    if (A.size() == 0)
        return 0 ;
    
    int i, maxi, j, ans, N = A.size () ;
    vector<int> dp (N, 1) ;
    
    ans = 1 ;
    for (j = 1 ; j < N ; j++)
    {
        maxi = -1 ;
        for (i = 0 ; i < j ; i++)
        {
            if (A[i][1] < A[j][0] && dp[i] >= maxi)
                maxi = dp[i] ;
        }
        
        if (maxi != -1)
        {
            dp[j] = maxi + 1 ;
            if (dp[j] > ans)
                ans = dp[j] ;
        }
    }
    
    return ans ;
}

