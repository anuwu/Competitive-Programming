vector<int> Solution::maxone(vector<int> &A, int B)
{
    int i, j, ones, maxones, maxi, maxj, flips, N = A.size() ;
    vector<int> ans ;
    
    maxones = INT_MIN ;
    flips = ones = i = j = 0 ;
    do
    {
        if (flips > B)
        {
            
            if (ones + B > maxones)
            {
                maxones = ones + B ;
                maxi = i ;
                maxj = j - 1 ;
            }
                
            while (A[i])
            {
                ones-- ;
                i++ ;
            }
            
            i++ ;
            flips -= 2 ;
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
                    break ;
                else
                    j++ ;
                    
            } while (j < N) ;
        }
    } while (j < N) ;
    
    if (ones + flips > maxones)
    {
        maxones = ones + flips ;
        maxi = i ;
        maxj = N-1 ;
    }
    
    for (i = maxi ; i <= maxj ; i++)
        ans.push_back (i) ;
    
        
    return ans ;
}

