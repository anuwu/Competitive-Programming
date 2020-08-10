class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int i, N = cost.size() ;
        
        vector<int> dp (N+1, 0) ;
        dp[0] = 0 ;
        dp[1] = 0 ;
        
        for (i = 2 ; i <= N ; i++)
            dp[i] = min (dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]) ;
        
        return dp[N] ;        
    }
};
