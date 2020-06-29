int Solution::removeDuplicates(vector<int> &A) 
{
    int repl, seOcc, thOcc, cnt, N = A.size () ;
    
    repl = 1 ;
    while (repl < N - 1 && (A[repl] != A[repl-1] || A[repl] != A[repl+1]))
        repl++ ;
        
    if (repl == N - 2)
        return N - 1 ;
    else if (repl == N - 3 && A[N-1] == A[N-2])
        return N - 2 ;
    
    seOcc = repl++ ;
    cnt = 0 ;
    do
    {
        thOcc = seOcc + 1 ;
        while (thOcc < N && A[thOcc] == A[seOcc])
        {
            thOcc++ ;
            cnt++ ;
        }
        
        if (thOcc == N)
            break ;
            
        seOcc = thOcc ;
        while (seOcc < N - 1 && (A[seOcc] != A[seOcc-1] || A[seOcc] != A[seOcc+1]))
        {
            A[repl] = A[seOcc] ;
            repl++ ;
            seOcc++ ;
        }
            
        A[repl] = A[seOcc] ;
        repl++ ;
    } while (seOcc < N - 1) ;
    
    return N - cnt ;
}

