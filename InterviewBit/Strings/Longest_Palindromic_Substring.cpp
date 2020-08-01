string Solution::longestPalindrome(string A) 
{
    int i, j, cent, maxlen, maxi, maxj, L = A.length() ;
    
    maxlen = 1 ;
    maxi = maxj = 0 ;
    
    for (cent = 1 ; cent < L ; cent++)
    {
        i = cent - 1 ;
        j = cent ;
        
        while (i >= 0 && j < L && A[i] == A[j])
        {
            if (j-i+1 > maxlen)
            {
                maxlen = j-i+1 ;
                maxi = i ;
                maxj = j ;
            }
            
            i-- ;
            j++ ;
        }
    }
    
    for (cent = 1 ; cent < L-1 ; cent++)
    {
        i = cent - 1 ;
        j = cent + 1 ;
        
        while (i >= 0 && j < L && A[i] == A[j])
        {
            if (j-i+1 > maxlen)
            {
                maxlen = j-i+1 ;
                maxi = i ;
                maxj = j ;
            }
            
            i-- ;
            j++ ;
        }
    }
    
    
    return A.substr (maxi, maxj - maxi + 1) ;
}

