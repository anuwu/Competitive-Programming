void Solution::setZeroes(vector<vector<int> > &A) 
{
    int i, j, R, C ;
    bool row_flag, col_flag ;
    
    R = A.size () ;
    C = A[0].size () ;
    row_flag = false ;
    col_flag = false ;
    
    for (j = 0 ; j < C ; j++)
    {
        if (!A[0][j])
        {
            row_flag = true ;
            break ;
        }
    }
    
    for (i = 0 ; i < R ; i++)
    {
        if (!A[i][0])
        {
            col_flag = true ;
            break ;
        }
    }
    
    for (i = 1 ; i < R ; i++)
    {
        for (j = 1 ; j < C ; j++)
        {
            if (!A[i][j])
            {
                A[0][j] = 0 ;
                A[i][0] = 0 ;
            }
        }
    }
    
    for (i = 1 ; i < R ; i++)
    {
        for (j = 1 ; j < C ; j++)
        {
            if (!A[i][0] || !A[0][j])
                A[i][j] = 0 ;
        }
    }
    
    if (row_flag)
    {
        for (j = 0 ; j < C ; j++)
            A[0][j] = 0 ;
    }

    if (col_flag)
    {
        for (i = 0 ; i < R ; i++)
            A[i][0] = 0 ;
    }
}

