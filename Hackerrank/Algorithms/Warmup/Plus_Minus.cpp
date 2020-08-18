void plusMinus(vector<int> A) 
{
    int i, pos, neg, zero, N = A.size() ;
    float r1, r2, r3 ;

    pos = neg = zero = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] > 0)
            pos++ ;
        else if (A[i] < 0)
            neg++ ;
        else
            zero++ ;
    }

    r1 = pos/(float)N ;
    r2 = neg/(float)N ;
    r3 = zero/(float)N ;

    printf ("%.6f\n%.6f\n%.6f\n", r1, r2, r3) ;
}
