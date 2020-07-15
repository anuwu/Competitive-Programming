class Solution {
public:
    int longestOnes(vector<int>& A, int K) 
    {
        int i, j, ones, maxones, flips, N = A.size() ;
        
        ones = 0 ;
        flips = 0 ;
        maxones = INT_MIN ;
        i = 0 ;
        j = 0 ;
        do
        {
            if (flips == K)
            {
                if (ones + K > maxones)
                    maxones = ones + K ;
                
                while (A[i])
                {
                    if (A[i])
                        ones-- ;
                    i++ ;
                }
                
                i++ ;
                flips-- ;
            }
            else
            {
                while (j < N)
                {
                    if (A[j])
                        ones++ ;
                    else
                        flips++ ;
                    
                    if (flips > K)
                    {
                        flips-- ;
                        break ;
                    }
                    else
                        j++ ;
                }
            }
        } while (j < N) ;
        
        if (ones + flips > maxones)
            maxones = ones + flips ;
        
        return maxones ;
    }
};
