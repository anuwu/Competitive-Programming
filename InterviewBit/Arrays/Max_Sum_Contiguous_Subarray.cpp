int Solution::maxSubArray(const vector<int> &A) 
{
    if (A.size () == 0)
        return 0 ;
    
    long long sumEnd, ans ;
    sumEnd = ans = A[0] ;
    
    for (int i = 1 ; i < A.size () ; i++)
    {
        if (sumEnd <= 0)
            sumEnd = A[i] ;
        else
            sumEnd += A[i] ;
            
        ans = max (sumEnd, ans) ;
    }
    
    return ans ;
}
