int Solution::solve(vector<int> &A) 
{
    int l, r, mid, N = A.size() ;
    
    l = 0 ;
    r = N - 1 ;
    
    while (l <= r)
    {
        mid = l + (r - l)/2 ;
        if ((mid == 0 || A[mid-1] <= A[mid]) && (mid == N-1 || A[mid] >= A[mid+1]))
            return A[mid] ;
        else if (A[mid-1] > A[mid])
            r = mid - 1 ;
        else
            l = mid + 1 ;
    }
}

