int Solution::isPower(int N) 
{
    if (N == 1)
        return 1 ;
        
    int i, expo ;
    for (i = 2 ; i*i <= N ; i++)
    {
        expo = log(N)/log(i) ;
        if (pow (i, expo) == N)
            return 1 ;
    }
    
    return 0 ;
}

