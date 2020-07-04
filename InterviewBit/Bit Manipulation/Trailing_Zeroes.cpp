int Solution::solve(int A) 
{
    if (A % 2)
        return 0 ;
        
    int cnt, rem ;
    cnt = 0 ;
    do
    {
        cnt++ ;
        A /= 2 ;
        rem = A % 2 ;
    } while (rem == 0) ;
    
    return cnt ;
}
