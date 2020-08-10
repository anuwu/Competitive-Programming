class Solution {
public:
    int firstBadVersion(int n) 
    {
        int lo, hi, mid, ans ;
        
        ans = n ;
        lo = 1 ;
        hi = n ;
        while (lo <= hi)
        {
            mid = lo + (hi - lo)/2 ;
            if (isBadVersion (mid))
            {
                ans = mid ;
                hi = mid - 1 ;
            }
            else
                lo = mid + 1 ;
        }
        
        return ans ;        
    }
};
