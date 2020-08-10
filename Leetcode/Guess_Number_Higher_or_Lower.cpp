class Solution {
public:
    int guessNumber(int n) 
    {
        int lo, hi, mid ;
        
        lo = 1 ;
        hi = n ;
        do
        {
            mid = lo + (hi - lo)/2 ;
            if (!guess(mid))
                return mid ;
            else if (guess(mid) == 1)
                lo = mid + 1 ;
            else
                hi = mid - 1 ;
        } while (true) ;
    }
};
