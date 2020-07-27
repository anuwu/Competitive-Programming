int Solution::maximumGap(const vector<int> &A) 
{
    int i, j, tmp, maxdiff, N = A.size() ;
    vector<int> Lmin (N, 0), Rmax (N, 0) ;
    
    Lmin[0] = A[0] ;
    for (i = 1 ; i < N ; i++)
        Lmin[i] = min (Lmin[i-1], A[i]) ;
        
    Rmax[N-1] = A[N-1] ;
    for (i = N-2 ; i >= 0 ; i--)
        Rmax[i] = max (Rmax[i+1], A[i]) ;
        
        
    maxdiff = 0 ;
    i = j = 0 ;
    while (i < N && j < N)
    {
        if (Lmin[i] <= Rmax[j])
        {
            maxdiff = max (maxdiff, j-i) ;
            j++ ;
        }
        else
            i++ ;
    }
    
    return maxdiff ;
}

