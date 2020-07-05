int findMin(vector<int>& nums) 
{
    int l, r, mid, N, fin ;

    N = nums.size() ;
    l = 0 ;
    r = N - 1 ;

    if (nums[l] < nums[r])
        return nums[0] ;

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
        fin = l+1 ;
    else
        fin = l ;

    return nums[fin] ;
}