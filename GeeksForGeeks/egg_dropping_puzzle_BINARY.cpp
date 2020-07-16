long long binomialSum (int n, int r)
{
    int i ;
    long long sum, term ;
    
    sum = n ;
    term = n ;
    for (i = 2 ; i <= min (n, r) ; i++)
    {
        term *= (n-i+1) ;
        term /= i ;
        sum += term ;
    }
    
    return sum ;
}


int Solution::solve(int E, int F) 
{
    if (E == 1)
        return F ;
        
    int low, high, mid ;
    long long binsum ;
    
    low = 0 ;
    high = F ;
    while (low <= high)
    {
        mid = low + (high - low)/2 ;
        binsum = binomialSum (mid, E) ;
        if (binsum < (long long)F)
            low = mid + 1 ;
        else
            high = mid - 1 ;
    }
    
    return low ;
}

