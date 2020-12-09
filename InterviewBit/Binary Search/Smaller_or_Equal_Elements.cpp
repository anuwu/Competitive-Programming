int Solution::solve(vector<int> &A, int B) 
{
    int lo, mid, hi, ans, N=A.size() ;
    
    ans = 0 ;
    lo = 0 ;
    hi = N-1 ;
    while (lo <= hi)
    {
        mid = lo + (hi - lo)/2 ;
        if (A[mid] <= B)
        {
            ans = mid ;
            lo = mid+1 ;
        }
        else
            hi = mid-1 ;
    }
    
    return ans + 1 ;
}

