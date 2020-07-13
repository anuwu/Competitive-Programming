int Solution::solve(int A) 
{
    if (A == 1)
        return 1 ;
    else if (A <= 3)
        return 2 ;
    
    int p = 2 ;
    do p *= 2 ; while (p < A) ;
    
    if (p == A)
        return A ;
    else
        return p/2 ;
}

