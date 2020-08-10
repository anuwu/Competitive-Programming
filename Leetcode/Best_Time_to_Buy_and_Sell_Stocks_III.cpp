class Solution {
public:
    int maxProfit(vector<int>& A) 
    {
        if (A.size() <= 1)
            return 0 ;
        
        int i, j, sumi, sumj, maxsum, minsum, sumEnd, N = A.size() ;
        vector<int> leftmss (N, 0), leftsum (N, 0), rightsum (N, 0) ;
        
        i = N-1 ;
        do
        {
            A[i] -= A[i-1] ;
            i-- ;
        } while (i > 0) ;
        A[0] = 0 ;
        
        leftmss[0] = 0 ;
        maxsum = sumEnd = 0 ;
        sumj = 0 ;
        i = 1 ;
        do
        {
            if (sumEnd < 0)
                sumEnd = A[i] ;
            else
                sumEnd += A[i] ;
            
            if (sumEnd > maxsum)
            {
                maxsum = sumEnd ;
                sumj = i ;
                leftmss[i] = i ;
                leftsum[i] = sumEnd ;
            }
            else
            {
                leftmss[i] = sumj ;
                leftsum[i] = maxsum ;
            }
            
            i++ ;
        } while (i < N) ;
        
        rightsum[N-1] = A[N-1] ;
        maxsum = sumEnd = A[N-1] ;
        sumi = N-1 ;
        j = N-2 ;
        do
        {
            if (sumEnd < 0)
                sumEnd = A[j] ;
            else
                sumEnd += A[j] ;
            
            if (sumEnd > maxsum)
            {
                maxsum = sumEnd ;
                sumi = j ;
                rightsum[j] = sumEnd ;
            }
            else
                rightsum[j] = maxsum ;
            
            j-- ;
        } while (j >= 0) ;
        

        int r, stocksum, stockmax = INT_MIN ;
        
        for (i = 0 ; i < N ; i++)
            if (leftsum[i] > stockmax)
                stockmax = leftsum[i] ;
        
        for (i = 0 ; i < N ; i++)
        {
            r = leftmss[i] + 2 ;
            stocksum = leftsum[i] + (r < N ? rightsum[r] : 0) ;
            
            if (stocksum > stockmax)
                stockmax = stocksum ;
        }
        
        return stockmax ;
    }
};
