class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        int i ;
        vector<int> ans (2*n, 0) ;
        
        for (i = 0 ; i < n ; i++)
        {
            ans[2*i] = nums[i] ;
            ans[2*i+1] = nums[i+n] ;
        }
        
        return ans ;
    }
};
