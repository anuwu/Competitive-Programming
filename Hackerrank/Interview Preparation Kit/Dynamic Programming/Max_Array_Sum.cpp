int maxSubsetSum(vector<int> A) 
{
    if (A.size() == 1)
        return A[0] ;
    else if (A.size() == 2)
        return max (A[0], A[1]) ;

    int i, tmp, incl, excl, N = A.size() ;

    incl = A[0] ;
    excl = 0 ;
    for (i = 1 ; i < N ; i++)
    {
        tmp = excl ;
        excl = max (incl, excl) ;

        incl = max (A[i], tmp + A[i]) ;
    }

    return max (incl, excl) ;
}
