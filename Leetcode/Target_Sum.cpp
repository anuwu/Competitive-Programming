class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int s, i, N = nums.size() ;
        if (S == INT_MAX)
            return false ;
        
        vector<vector<int>> DP(N, vector<int>(2001, 0)) ;
            
        DP[0][nums[0] + 1000] = 1 ;
        DP[0][-nums[0] + 1000] += 1 ;
        for (i = 1 ; i < N ; i++)
        {
            for (s = 0 ; s < 2001 ; s++)
            {
                // Add the number
                if (s-nums[i] >= 0)
                    DP[i][s] += DP[i-1][s-nums[i]] ;

                // Subtract the number
                if (s+nums[i] < 2001)
                    DP[i][s] += DP[i-1][s+nums[i]] ;
            }   
        }
        
        return S+1000<=2000 ? DP[N-1][S+1000]  : false ;
    }
};
