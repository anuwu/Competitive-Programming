int Solution::solve(vector<int> &A, int B) 
{
    int l, r, sum, len, N = A.size() ;
    
    len = INT_MAX ;
    l = 0 ;
    r = 0 ;
    sum = 0 ;
    do
    {
        if (sum < B)
        {
            sum += A[r] ;
            r++ ;
        }
        else
        {
            if (r - l < len)
                len = r - l ;
            
            sum -= A[l] ;
            l++ ;
        }
        
    } while (r < N) ;
    
    while (sum >= B && l < N)
    {
        if (r - l < len)
            len = r - l ;
        
        sum -= A[l] ;
        l++ ;
    }
    
    if (len == INT_MAX)
        return -1 ;
    else
        return len ;
}
