int Solution::solve(vector<vector<int> > &A) 
{
    int row, col, i, j, val, N = A.size(), M = A[0].size() ;
    
    if (N == 1 || M == 1)
        return 1 ;
    
    for (row = N-2 ; row >= 0 ; row--)
    {
        val = A[row][0] ;
        i = row + 1 ;
        j = 1 ;
        while (i < N && j < M)
        {
            if (A[i][j] != val)
                return 0 ;
            i++ ;
            j++ ;
        }
    }
    
    for (col = 1 ; col < M - 1 ; col++)
    {
        val = A[0][col] ;
        i = 1 ;
        j = col + 1 ;
        while (i < N && j < M)
        {
            if (A[i][j] != val)
                return 0 ;
            i++ ;
            j++ ;
        }
    }
    
    
    return 1 ;
}

