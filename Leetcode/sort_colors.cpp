class Solution {
public:
    void sortColors(vector<int>& A) 
    {
        if (A.size() <= 1)
            return ;
        
        int lo, mid, hi, tmp ;
        
        lo = 0 ;
        mid = 0 ;
        hi = A.size() - 1 ;
        while (mid <= hi)
        {
            if (A[mid] == 0)
            {
                tmp = A[lo] ;
                A[lo] = A[mid] ;
                A[mid] = tmp ;
                
                lo++ ;
                mid++ ;
            }
            else if (A[mid] == 1)
                mid++ ;
            else
            {
                tmp = A[mid] ;
                A[mid] = A[hi] ;
                A[hi] = tmp ;
                
                hi-- ;
            }
        }
    }
};
