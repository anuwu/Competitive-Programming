int Solution::searchInsert(vector<int> &A, int B) 
{
    int l, r, mid ;
    
    l = 0 ;
    r = A.size() - 1 ;
    while (l <= r)
    {
        mid = (l + r)/2 ;
        if (A[mid] == B)
            break ;
        else if (B < A[mid])
            r = mid - 1 ;
        else
            l = mid + 1 ;
    }
    
    if (l <= r)
        return mid ;
        
    return l ;
}

