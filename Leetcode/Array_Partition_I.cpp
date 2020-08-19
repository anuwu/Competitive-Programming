class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
    {
        int i, sum = 0, l = nums.size() ;
        
        sort (nums.begin(), nums.end()) ;
        sum = 0 ;
        for (i = l-2 ; i >= 0 ; i -= 2)
            sum += nums[i] ;
        
        return sum ;
    }
};
