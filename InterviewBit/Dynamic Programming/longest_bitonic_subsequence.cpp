int Solution::longestSubsequenceLength(const vector<int> &A) 
{
    if (A.size() == 0)
        return 0 ;
    
    int i, j, maxi, maxj, ans, N = A.size() ;
    vector<int> dp1 (N, 1), dp2 (N, 1) ;
    
    for (j = 1 ; j < N ; j++)
    {
        maxi = -1 ;
        for (i = 0 ; i < j ; i++)
            if (A[j] > A[i] && dp1[i] > maxi)
                maxi = dp1[i] ;
                
        if (maxi != -1)
            dp1[j] = maxi + 1 ;
    }
    
    for (i = N-2 ; i >= 0 ; i--)
    {
        maxj = -1 ;
        for (j = N-1 ; j > i ; j--)
            if (A[i] > A[j] && dp2[j] > maxj)
                maxj = dp2[j] ;
                
        if (maxj != -1)
            dp2[j] = maxj + 1 ;
    }
    
    ans = 0 ;
    for (i = 0 ; i < N ; i++)
        if (dp1[i] + dp2[i] > ans)
            ans = dp1[i] + dp2[i] ;
    
    return ans-1 ;
}

