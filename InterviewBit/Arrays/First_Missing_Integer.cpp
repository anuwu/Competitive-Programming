
int firstMissing (int* A, int N)
{
    int i, ind ;
    
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] > 0)
            ind = A[i] - 1;
        else
            ind = -A[i] - 1 ;
        
        if (0 <= ind && ind < N && A[ind] > 0)
            A[ind] *= -1 ; 
    }
    
    for (i = 1 ; i <= N ; i++)
        if (A[i-1] > 0)
            return i ;
            
    return N+1 ;
}


int firstMissingPositive(int* A, int N) 
{
    int lo, hi, tmp ;
    
    lo = 0 ;
    hi = N-1 ;
    while (lo <= hi)
    {
        if (A[lo] <= 0)
            lo++ ;
        else
        {
            tmp = A[lo] ;
            A[lo] = A[hi] ;
            A[hi] = tmp ;
            
            hi-- ;
        }
    }

    if (lo == N)
        return 1 ;
    else
        return firstMissing (A + lo, N - lo) ;
}

