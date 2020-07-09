void lsis (vector<int> &A)
{
    int i, j, maxi, ans, N = A.size () ;
    vector<int> dp (A) ;
    
    ans = A[0] ;
    for (j = 1 ; j < N ; j++)
    {
        maxi = -1 ;
        for (i = 0 ; i < j ; i++)
            if (A[j] > A[i] && dp[i] > maxi)
                maxi = dp[i] ;
                
        if (maxi != -1)
        {
            dp[j] = maxi + A[j] ;
            if (dp[j] > ans)
                ans = dp[j] ;
        }
        else if (A[j] > ans)
            ans = A[j] ;
    }
    
    cout << ans << "\n" ;
}
