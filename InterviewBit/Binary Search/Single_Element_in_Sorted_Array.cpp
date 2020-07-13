
int searchSingle (vector<int> &A, int l, int r)
{
    if (l > r)
        return - 1 ;
        
    int mid ;
    mid = (l + r)/2 ;
    
    if (mid == 0)
    {
        if (A[mid] != A[mid+1])
            return A[0] ;
        else
            return -1 ;
    }
    
    if (mid == A.size() - 1 && A[mid] != A[mid-1])
    {
        if (A[mid] != A[mid-1])
            return A[mid] ;
        else
            return -1 ;
    }
    

    if (A[mid] != A[mid-1] && A[mid] != A[mid+1])
        return A[mid] ;
    else
    {
        
        int left, right ;
        left = searchSingle (A, l, mid-1) ;
        right = searchSingle (A, mid+1, r) ;
        
        return left != -1 ? left : right ;
    }
}

int Solution::solve(vector<int> &A) 
{
    return searchSingle (A, 0, A.size()-1) ;
}

