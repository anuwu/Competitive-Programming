int Solution::solve(vector<int> &A, int B)
{
    int low, high, mid, N = A.size() ;
    
    low = 0 ;
    high = N-1 ;
    while (low <= high)
    {
        mid = low + (high - low)/2 ; 
        if ((mid == 0 || A[mid-1] < A[mid]) && (mid == N-1 || A[mid] > A[mid+1]))
            break ;
        else if (A[mid-1] >= A[mid])
            high = mid - 1 ;
        else
            low = mid + 1 ;
    }
    
    if (A[mid] == B)
        return mid ;
        
    low = 0 ;
    high = mid - 1 ;
    while (low <= high)
    {
        mid = low + (high - low)/2 ;
        if (A[mid] == B)
            return mid ;
        else if (A[mid] > B)
            high = mid - 1 ;
        else
            low = mid + 1 ;
    }

    low = mid + 1  ;
    high = N - 1 ;
    while (low <= high)
    {
        mid = low + (high - low)/2 ;
        if (A[mid] == B)
            return mid ;
        else if (A[mid] > B)
            low = mid + 1 ;
        else
            high = mid - 1 ;
    }
    

    return -1 ;
}

