int Solution::maxProfit(const vector<int> &A) 
{
    if (A.size() < 2)
        return 0 ;
        
    int i, runmin, maxdiff, N = A.size() ;
    
    runmin = A[0] ;
    maxdiff = 0 ;
    for (i = 1 ; i < N ; i++)
    {
        if (A[i] < runmin)
            runmin = A[i] ;
        else if (A[i] - runmin > maxdiff)
            maxdiff = A[i] - runmin ;
    }
    
    return maxdiff ;
}

