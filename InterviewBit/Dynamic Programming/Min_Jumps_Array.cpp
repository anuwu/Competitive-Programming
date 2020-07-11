int Solution::jump(vector<int> &A) 
{
    if (A.size () < 2)
        return 0 ;
        
    int i, maxreach, nextmax, jumps, N = A.size () ;
    
    jumps = 0 ;
    i = 0 ;
    maxreach = 0 ;
    while (true)
    {
        nextmax = maxreach ;
        for ( ; i <= maxreach ; i++)
            nextmax = max (nextmax, i + A[i]) ;
        
        if (nextmax == maxreach)
            return -1 ;
        
        jumps++ ;
        i = maxreach ;
        maxreach = nextmax ;
        if (maxreach >= N - 1)
            return jumps ;
    }
}

