class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int low, high, mid ;
        
        low = 0 ;
        high = nums.size() - 1 ;
        while (low <= high)
        {
            mid = low + (high - low)/2 ;
            if (nums[mid] == target)
                return true ;
            else
            {
                if (target == nums[low])
                    return true ;
                if (target == nums[high])
                    return true ;
                
                if (target > nums[low])
                {
                    if (nums[mid] > target)
                        high = mid - 1 ;
                    else if (nums[mid] == nums[low])
                        low++ ;
                    else if (nums[mid] > nums[low])
                        low = mid + 1 ;
                    else
                        high = mid - 1 ;
                        
                }
                else // target < nums[high]
                {
                    if (nums[mid] < target)
                        low = mid + 1 ;
                    else if (nums[mid] == nums[high])
                         high-- ;
                    else if (nums[mid] < nums[high])
                        high = mid - 1 ;
                    else
                        low = mid + 1 ;
                }
            }
        }
        
        return false ;
    }
};
