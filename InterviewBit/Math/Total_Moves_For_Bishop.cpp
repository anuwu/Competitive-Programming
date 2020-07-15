int Solution::solve(int A, int B) 
{
    int cnt, i, j ;
    
    cnt = -4 ;
    i = A ;
    j = B ;
    do
    {
        i-- ;
        j-- ;
        cnt++ ;
    } while (i > 0 && j > 0) ;
    
    i = A ;
    j = B ;
    do
    {
        i++ ;
        j-- ;
        cnt++ ;
    } while (i <= 8 && j > 0) ;
    
    i = A ;
    j = B ;
    do
    {
        i-- ;
        j++ ;
        cnt++ ;
    } while (i > 0 && j <= 8) ;
    
    i = A ;
    j = B ;
    do
    {
        i++ ;
        j++ ;
        cnt++ ;
    } while (i <= 8 && j <= 8) ;
    
    return cnt ;
}

