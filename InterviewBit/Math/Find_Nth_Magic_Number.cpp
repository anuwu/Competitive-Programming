int Solution::solve(int A) 
{
    int i, expo = 1, fiv = 5, magic ;
    
    magic = 0 ;
    for (i = 0 ; i < 13 ; i++)
    {
        magic += (A & 1)*fiv ;
        A >>= 1 ;
        fiv *= 5 ;
    }
    
    return magic ;
}

