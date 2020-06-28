int Solution::perfectPeak(vector<int> &A) 
{
    vector<int> maxflag (A.size(), 0), minflag(A.size(), 0) ;
    int i, j, max, min ;
    
    max = A[0] ;
    min = A[A.size() - 1] ;
    
    for (i = 1, j = A.size() - 1 ; i < A.size() - 1 && j > 0 ; i++, j--)
    {
        if (A[i] > max)
        {
            printf ("Max(%d) ", A[i]) ;
            maxflag[i] = 1 ;
            max = A[i] ;
        }
        
        
        if (A[j] < min)
        {
            printf ("Min(%d) ", A[j]) ;
            minflag[j] = 1 ;
            min = A[j] ;
        }
    }
    
    for (i = 0 ; i < A.size() ; i ++)
        printf ("\n%d = (%d,%d)", A[i], maxflag[i], minflag[i]) ;
        
    printf ("\n") ;
    return 0 ;
}
