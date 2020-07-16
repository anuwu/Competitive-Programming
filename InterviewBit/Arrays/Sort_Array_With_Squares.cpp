vector<int> Solution::solve(vector<int> &A) 
{
    int i, j, k, N = A.size() ;
    vector<int> ans (N, 0) ;
    
    i = 0 ;
    while (i < N && A[i] < 0)
    {
        A[i] = -A[i] ;
        i++ ;
    }
    
    j = i ;
    i-- ;
    
    k = 0 ;
    while (i >= 0 && j < N)
    {
        if (A[i] < A[j])
        {
            ans[k] = A[i]*A[i] ;
            k++ ;
            i-- ;
        }
        else
        {
            ans[k] = A[j]*A[j] ;
            j++ ;
            k++ ;
        }
    }
    
    while (i >= 0)
    {
        ans[k] = A[i] * A[i] ;
        k++ ;
        i-- ;
    }
    
    while (j < N)
    {
        ans[k] = A[j] * A[j] ;
        k++ ;
        j++ ;
    }
    
    return ans ;
}

