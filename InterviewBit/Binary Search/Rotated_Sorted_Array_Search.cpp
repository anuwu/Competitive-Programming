int Solution::search(const vector<int> &A, int B) 
{
    int l, r, mid, rot, N ;

    N = A.size() ;
    l = 0 ;
    r = N - 1 ;

    if (A[l] < A[r])
        rot = 0 ;
    else
    {
        while (r - l > 1)
        {
            mid = (l+r)/2 ;
            if (A[mid] > A[l])
            {    
                if (A[mid+1] > A[mid])
                    l = mid + 1 ;
                else if (A[r-1] > A[r])
                    l = mid ;
                else
                    r-- ;
            }
            else
                r = mid ;            
        }
        
        rot = r ;
    }

    l = 0 ;
    r = N-1 ;
    while (l <= r)
    {
        mid = (l+r)/2 ;
        if (A[(mid+rot)%N] ==B)
            return (mid+rot)%N ;
        else if (B > A[(mid+rot)%N])
            l = mid + 1 ;
        else
            r = mid - 1 ;
    }
    
    return -1 ;
}
