int Solution::solve(vector<vector<int> > &A) 
{
    int i, j, minrow, maxones, R = A.size(), C = A[0].size() ;
    
    minrow = 0 ;
    maxones = INT_MIN ;
    for (i = 0 ; i < R ; i++)
    {
        if (A[i][0] == 1)
            return i ;
        else if (A[i][C-1] == 0)
            continue ;
        
        for (j = 0 ; j < C ; j++)
            if (A[i][j])
                break ;
        
        if (C - j > maxones)
        {
            minrow = i ;
            maxones = C - j ;
        }
    }
    
    return minrow ;
}

