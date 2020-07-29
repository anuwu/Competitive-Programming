#define MOD 1000000007

int Solution::numDecodings(string S) 
{
    int i, N = S.length() ;
    
    if (N == 0)
        return 1 ;
    else if (N == 1)
    {
        if (S[0] == '0')
            return 0 ;
        return 1 ;
    }
    
    if (S[0] == '0')
        return 0 ;
    
    vector<long long> dp (N+1, 1) ;
    
    for (i = 1 ; i < N ; i++)
    {
        if (S[i] == '0' && S[i-1] != '1' && S[i-1] != '2')
            return 0 ;
            
        if (S[i-1] == '1')
        {
            if (S[i] == '0')
                dp[i+1] = dp[i-1] ;
            else
                dp[i+1] = (dp[i] + dp[i-1]) % MOD ;
        }
        else if (S[i-1] == '2')
        {
            if (S[i] == '0')
                dp[i+1] = dp[i-1] ;
            else if (S[i] >= '1' && S[i] <= '6')
                dp[i+1] = (dp[i] + dp[i-1]) % MOD ;
            else
                dp[i+1] = dp[i] ;
        }
        else
            dp[i+1] = dp[i] ;
    }
    
    return dp[N] ;
}

