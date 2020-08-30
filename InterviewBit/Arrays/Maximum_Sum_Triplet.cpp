int Solution::solve(vector<int> &A) 
{
    int ans, trip, maxnum, maxi, N = A.size() ;
    vector<int> rmax (N, -1) ;
    set<int> lmax ;
    
    maxi = N-1 ;
    maxnum = A[N-1] ;
    for (int i = N-2 ; i >= 0 ; i--)
    {
        if (A[i] >= maxnum)
        {
            rmax[i] = -1 ;
            maxnum = A[i] ;
            maxi = i ;
        }
        else
            rmax[i] = maxi ;
    }
    
    ans = INT_MIN ;
    lmax.insert (A[0]) ;
    for (int j = 1 ; j < N-1 ; j++)
    {
        lmax.insert (A[j]) ;
        int k = rmax[j] ;
        if (k == -1)
            continue ;
            
        auto i = lmax.lower_bound (A[j]) ;
        if (i == lmax.begin())
            continue ;
            
        i-- ;
        trip = *i + A[j] + A[k] ;
        if (trip > ans)
            ans = trip ;
    }
    
    if (ans == INT_MIN)
        return 0 ;
        
    return ans ;
}

