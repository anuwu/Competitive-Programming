int Solution::solve(string s) 
{
    int i, j, l, len = s.length () ;
    vector<vector<int>> dp (len, vector<int> (len, 1)) ;
    
    for (l = 2 ; l <= len ; l++)
    {
        for (i = 0 ; i <= len - l ; i++)
        {
            j = i + l - 1 ;
            if (s[i] == s[j])
            {
                if (l == 2)
                    dp[i][j] = 2 ;
                else
                    dp[i][j] = dp[i+1][j-1] + 2 ;
            }
            else
                dp[i][j] = max (dp[i+1][j], dp[i][j-1]) ;
        }
    }
    
    return dp[0][len-1] ;
}

