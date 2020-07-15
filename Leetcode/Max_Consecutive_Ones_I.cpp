class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int i, ones, max, N = nums.size() ;
        bool consec = false ;
        
        i = 0 ;
        max = INT_MIN ;
        do
        {
            while (i < N && !nums[i])
                    i++ ;
            
            ones = 0 ;
            while (i < N && nums[i++])
                ones++ ;
            
            if (ones > max)
                max = ones ;
        } while (i < N) ;
        
        if (max == INT_MIN)
            return 0 ;
        else
            return max ;
        
    }
};
