string Solution::solve(string A) 
{
    int i, p, sq, N = A.length () ;
    vector<bool> sieve (N+1, false) ;
    
    sieve[1] = true ;
    p = 2 ;
    sq = 4 ;
    while (sq <= N)
    {
        while (sq <= N)
        {
            sieve[sq] = true ;
            sq += p ;
        }
        
        do p++ ; while (sieve[p]) ;
        sq = p*p ;
    }
    
    for (i = 1 ; i <= N ; i++)
    {
        if (A[i-1] == 'a' || A[i-1] == 'e' || A[i-1] == 'i' || A[i-1] == 'o' || A[i-1] == 'u')
        {
            if (sieve[i])
                return "NO" ;
        }
    }
    
    return "YES" ;
}

