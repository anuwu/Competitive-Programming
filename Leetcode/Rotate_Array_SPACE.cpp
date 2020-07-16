class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        if (k == 0)
            return ;
        
        k = k % nums.size() ;
        
        vector<int> cut ;
        cut = vector (nums.begin() + nums.size() - k, nums.end()) ;
        nums.erase (nums.begin() + nums.size() - k, nums.end()) ;
        
        nums.insert (nums.begin(), cut.begin(), cut.end()) ;
    }
};
