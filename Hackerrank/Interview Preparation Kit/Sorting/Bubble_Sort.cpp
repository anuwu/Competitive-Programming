void countSwaps(vector<int> A) 
{
    int i, j, tmp, sw, N = A.size() ;

    sw = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; j < N - i - 1 ; j++)
        {
            if (A[j] > A[j+1])
            {
                tmp = A[j] ;
                A[j] = A[j+1] ;
                A[j+1] = tmp ;
                sw++ ;
            }
        }
    }

    printf ("Array is sorted in %d swaps.\n", sw) ;
    printf ("First Element: %d\n", A[0]) ;
    printf ("Last Element: %d\n", A[N-1]) ;
}
