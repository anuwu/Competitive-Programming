bool search(vector<int>& nums, int target) 
{
    int l, r, mid, N, rot ;

    N = nums.size() ;
    l = 0 ;
    r = N - 1 ;

    if (nums[l] < nums[r])
        rot = 0 ;

    while (r - l > 1)
    {
        mid = l + (r-l)/2 ;
        if (nums[mid] == nums[r])
            r-- ;
        else if (nums[mid] >= nums[l])
        {
            if (nums[mid+1] >= nums[mid])
                l = mid + 1 ;
            else if (nums[r-1] > nums[r])
                l = mid ;
            else
                r-- ;
        }
        else
            r = mid ;
    }

    if (nums[l] != nums[l+1])
        rot = l+1 ;
    else
        rot = l ;

    l = 0 ;
    r = N-1 ;
    while (l <= r)
    {
        mid = (l+r)/2 ;
        if (nums[(mid+rot)%N] == target)
            return true ;
        else if (target > nums[(mid+rot)%N])
            l = mid + 1 ;
        else
            r = mid - 1 ;
    }
    
    return false ;
    
}