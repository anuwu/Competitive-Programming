int Solution::solve(int A) 
{
    int step, sum ;
    A = abs (A) ;
    
    step = 0 ;
    sum = 0 ; 
    while (sum < A)
    {
        step++ ;
        sum += step ;
    }
    
    if (sum == A)
        return step ;
        
    while ((sum - A) % 2)
    {
        step++ ;
        sum += step ;
    }
        
    return step ;
}

