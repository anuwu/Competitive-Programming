int Solution::solve(vector<int> &A, int B) 
{
    int st, end, sum, minlen, N = A.size() ;
    
    st = 0 ;
    end = 0 ;
    sum = 0 ;
    minlen = INT_MAX ;
    
    do
    {
        if (sum < B)
        {
            sum += A[end] ;
            end++ ;
        }
        else
        {
            if (end - st  < minlen)
                minlen = end - st ;
            
            sum -= A[st] ;
            st++ ;
        }
    } while (end < N) ;
    
    while (sum >= B && st < N)
    {
        if (end - st < minlen)
            minlen = end - st ;
        
        sum -= A[st] ;
        st++ ;
    }
    
    if (minlen == INT_MAX)
        return 0 ;
    else
        return minlen ;
}

