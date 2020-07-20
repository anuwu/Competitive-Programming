int Solution::solve(vector<int> &A) 
{
    if (!A.size())
        return 0 ;
    if (A.size() == 1)
        return 1 ;
        
    int i, j, evensum, oddsum, cnt, N = A.size() ;
    vector<int> even (N, 0), odd (N, 0) ;
    
    i = N-1 ;
    if (i % 2)
    {
        odd[i] = A[i] ;
        even[i-1] = A[i-1] ;
    }
    else
    {
        even[i] = A[i] ;
        odd[i-1] = A[i-1] ;
    }
    
    for (i = N-3 ; i >= 0 ; i--)
    {
        if (i % 2)
            odd[i] = A[i] + odd[i+2] ;
        else
            even[i] = A[i] + even[i+2] ;
    }
    
    cnt = 0 ;
    for (i = N-1 ; i >= 0 ; i--)
    {
        if (i % 2)
        {
            oddsum = odd[1] - odd[i] + (i+1 < N ? even[i+1] : 0) ;
            evensum = even[0] - (i+1 < N ? even[i+1] : 0) + odd[i] - A[i] ; 
        }
        else
        {
            evensum = even[0] - even[i] + (i+1 < N ? odd[i+1] : 0) ;
            oddsum = odd[1] - (i+1 < N ? odd[i+1] : 0) + even[i] - A[i] ; 
        }
        
        if (evensum == oddsum)
            cnt++ ;
    }
    
    return cnt ;
}

