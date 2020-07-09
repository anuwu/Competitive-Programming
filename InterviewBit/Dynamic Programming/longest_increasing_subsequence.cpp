int Solution::lis(const vector<int> &A) 
{
    int i, j, l, maxlis, ans, N = A.size () ;
    vector<int> lis (N, 1) ;
    
    ans = 1 ;
    for (j = 1 ; j < N ; j++)
    {
        maxlis = -1 ;
        for (i = 0 ; i < j ; i++)
            if (A[j] > A[i] && lis[i] > maxlis)
                maxlis = lis[i] ;
                
        if (maxlis > 0)
        {
            lis[i] = maxlis + 1 ;
            if (lis[i] > ans)
                ans = lis[i] ;
        }
    }
    
    return ans ;
}

