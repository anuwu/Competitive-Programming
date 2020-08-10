class Solution {
public:
    int searchInsert(vector<int>& A, int target) 
    {
        int lo, hi, mid, ans, N = A.size() ;
        
        lo = ans = 0 ;
        hi = N-1 ;
        while (lo <= hi)
        {
            mid = lo + (hi - lo)/2 ;
            if (A[mid] == target)
            {
                ans = mid ;
                break ;
            }
            else if (A[mid] < target)
            {
                ans = mid + 1 ;
                lo = mid + 1 ;
            }
            else
                hi = mid - 1 ;
        }
        
        return ans ;
    }
};
