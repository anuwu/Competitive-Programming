vector<vector<int> > Solution::generateMatrix(int A) 
{
    vector<vector<int>> mat (A, vector<int> (A)) ;
    int sti, stj, maxi, maxj, i, j, k ;
    
    sti = 0 ;
    stj = 0 ;
    maxi = A - 1 ;
    maxj = A - 1 ;
    k = 1 ;
    while (true)
    {
        if (sti == maxi && stj == maxj)
        {
            mat[sti][stj] = k ;
            break ;
        }
        
        for (j = stj ; j < maxj ; j++, k++)
            mat[sti][j] = k ;
            
        for (i = sti ; i < maxi ; i++, k++)
            mat[i][maxj] = k ;
            
        for (j = maxj ; j > stj ; j--, k++)
            mat[maxi][j] = k ;
            
        for (i = maxi ; i > sti ; i--, k++)
            mat[i][stj] = k ;
        
        sti++ ;
        stj++ ;
        maxi-- ;
        maxj-- ;
        if (k > A*A)
            break ;
    }
    
    return mat ;
}

