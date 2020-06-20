int Solution::searchMatrix(vector<vector<int> > &A, int B) 
{
    int rows, cols, start, end, mid, r, c ;
    
    rows = A.size () ; cols = A[0].size () ;
    start = 0 ; end = rows*cols - 1 ;
    while (start <= end)
    {
        mid = (start + end)/2 ;
        r = mid/cols ;
        c = mid - r*cols ;
        if (A[r][c] == B)
            return 1 ;
        else if (B < A[r][c])
            end = mid - 1 ;
        else
            start = mid + 1 ;
    }
    
    return 0 ;
}
