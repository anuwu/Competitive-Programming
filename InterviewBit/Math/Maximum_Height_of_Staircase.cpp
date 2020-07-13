int Solution::solve(int A) 
{
    if (A == 0 || A == 1)
        return A ;
    else if (A == 3)
        return 2 ;
    
    int n = sqrt (2*A) ;
    
    while (n*(n+1) > 2*A)
        n-- ;
        
    return n ;
}

