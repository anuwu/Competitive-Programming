int Solution::solve(vector<int> &A, int B) 
{
    int i, j, ones, maxones, flips, N = A.size() ;
    
    maxones = INT_MIN ;
    flips = ones = i = j = 0 ;
    do
    {
        if (flips == B)
        {
            if (ones + B > maxones)
                maxones = ones + B ;
                
            while (A[i])
            {
                ones-- ;
                i++ ;
            }
            
            i++ ;
            flips-- ;
        }
        else
        {
            do
            {
                if (A[j])
                    ones++ ;
                else
                    flips++ ;
                    
                if (flips > B)
                {
                    flips-- ;
                    break ;
                }
                else
                    j++ ;
            } while (j < N) ;
        }
    } while (j < N) ;
    
    if (ones + flips > maxones)
        maxones = ones + flips ;
        
    return maxones ;
}

