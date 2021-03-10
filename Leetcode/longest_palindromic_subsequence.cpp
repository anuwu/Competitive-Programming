class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int i, j, l, len = s.length() ;
        vector<vector<int>> dp(len, vector<int> (len, 1)) ;
        
        for (i = 0 ; i < len - 1 ; i++)
            if (s[i] == s[i+1])
                dp[i][i+1] = 2 ;
        
        for (l = 3 ; l <= len ; l++)
        {
            for (i = 0 ; i < len-l+1 ; i++)
            {
                j = i + l - 1 ;
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2 ;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]) ;
            }
        }
        
        return dp[0][len-1] ;
    }
};
