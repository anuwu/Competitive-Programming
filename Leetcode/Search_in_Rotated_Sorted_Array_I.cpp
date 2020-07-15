class Solution 
{
    
public:
    int search(vector<int>& nums, int target) 
    {
        int l, r, mid, N = nums.size() ;
        
        l = 0 ;
        r = N-1 ;
        while (l <= r)
        {
            mid = l + (r-l)/2 ;
            if (nums[mid] == target)
                return mid ;
            else
            {
                if (target == nums[l])
                    return l ;
                if (target == nums[r])
                    return r ;
                
                if (target > nums[l])
                {
                    if (nums[mid] > target)
                        r = mid - 1 ;
                    else if (nums[mid] < nums[l])
                        r = mid - 1;
                    else
                        l = mid + 1 ;
                }
                else // target < nums[r]
                {
                    if (nums[mid] < target)
                        l = mid + 1 ;
                    else if (nums[mid] > nums[r])
                        l = mid + 1 ;
                    else
                        r = mid - 1;
                }
            }
        }
        
        return -1 ;
    }
};
