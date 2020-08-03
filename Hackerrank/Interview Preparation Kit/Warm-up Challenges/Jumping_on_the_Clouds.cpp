int jumpingOnClouds(vector<int> A) 
{
    if (A.size() == 1)
        return 0 ;
    else if (A.size() == 2)
        return 1 ;

    int i, jmp, lim, N = A.size() ;

    jmp = 0 ;
    if (A[N-1] == 1)
    {
        if (A[N-2] == 1)
            lim = N-2 ;
        else
            lim = N-1 ;
    }
    else if (A[N-2] == 1)
        lim = N-2 ;
    else
    {
        lim = N ;
        jmp = -1 ;
    }

    i = 0 ;
    do
    {
        jmp++ ;
        if (!A[i+2])
            i += 2 ;
        else
            i++ ;   
    } while (i < lim) ;

    return jmp ;
}
