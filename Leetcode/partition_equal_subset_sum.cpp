class Solution {
public:
    bool canPartition(vector<int>& arr) 
    {
        int s, i, N = arr.size() ;
        long long sum = 0, halfsum ;
        for (i = 0 ; i < N ; i++)
            sum += arr[i] ;
            
        if (sum % 2)
            return 0 ;
            
        halfsum = sum/2 ;
        vector<vector<bool>> DP(halfsum + 1, vector<bool> (N, false)) ;
        for (i = 0 ; i < N ; i++)
            DP[0][i] = true ;
            
        for (s = 1 ; s <= halfsum ; s++)
        {
            for (i = 0 ; i < N ; i++)
            {            
                if (arr[i] <= s)
                    DP[s][i] = (i>=1 ? DP[s][i-1] : false) || (i >= 1 ? DP[s-arr[i]][i-1] : false) ;
                else 
                    DP[s][i] = (i>=1 ? DP[s][i-1] : false) ;
            }
        }
        
        return DP[halfsum][N-1] ;
    }
};
