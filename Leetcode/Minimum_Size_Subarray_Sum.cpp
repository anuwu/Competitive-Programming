class Solution {
public:
    int minSubArrayLen(int B, vector<int>& A) 
    {
        int l, r, sum = 0, len, N = A.size() ;
        
        l = 0 ;
        len = INT_MAX ;
        for (r = 0 ; r < N ; r++)
        {
            sum += A[r] ;
            while (sum >= B)
            {
                len = min (len, r - l + 1) ;
                sum -= A[l] ;
                l++ ;
            }
        }
        
        if (len == INT_MAX)
            return 0 ;
        else
            return len ;
    }
};
