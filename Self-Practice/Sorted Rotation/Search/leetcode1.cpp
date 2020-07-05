int search(vector<int>& nums, int target) 
{
    int l, r, mid, rot, N ;

    N = nums.size() ;
    l = 0 ;
    r = N - 1 ;

    if (nums[l] < nums[r])
        rot = 0 ;
    else
    {
        while (r - l > 1)
        {
            mid = (l+r)/2 ;
            if (nums[mid] > nums[l])
            {	
                if (nums[mid+1] > nums[mid])
                    l = mid + 1 ;
                else if (nums[r-1] > nums[r])
                    l = mid ;
                else
                    r-- ;
            }
            else
                r = mid ;			
        }
        
        rot = r ;
    }

    l = 0 ;
    r = N-1 ;
    while (l <= r)
    {
        mid = (l+r)/2 ;
        if (nums[(mid+rot)%N] == target)
            return (mid+rot)%N ;
        else if (target > nums[(mid+rot)%N])
            l = mid + 1 ;
        else
            r = mid - 1 ;
    }
    
    return -1 ;
}