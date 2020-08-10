class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int K, int x) 
    {
        int lo, hi, mid, clos, i, j, k, N = A.size() ;
        vector<int> ans ;
        
        lo = 0 ;
        hi = N-1 ;
        while (lo <= hi)
        {
            mid = lo + (hi - lo)/2 ;
            if (A[mid] == x)
            {
                clos = mid ;
                break ;
            }
            else if (A[mid] < x)
            {
                clos = mid ;
                lo = mid + 1 ;
            }
            else
                hi = mid - 1 ;
        }
        
        if (clos + 1 < N && abs(A[clos + 1] - x) < abs(A[clos] - x))
            clos++ ;
        
        ans.push_back (A[clos]) ;
        i = clos - 1 ;
        j = clos + 1 ;
        for (k = 1 ; i >= 0 && j < N && k < K ; k++)
        {
            if (abs(A[i] - x) <= abs(A[j] - x))
            {
                ans.push_back (A[i]) ;
                i-- ;
            }
            else
            {
                ans.push_back (A[j]) ;
                j++ ;
            }
        }
        
        if (i < 0)
            for ( ; k < K && j < N ; k++, j++)
                ans.push_back (A[j]) ;
        
        if (j == N)
            for ( ; k < K && i >= 0 ; k++, i--)
                ans.push_back (A[i]) ;
        
        sort (ans.begin(), ans.end()) ;
        return ans ;
    }
};
