vector<int> Solution::spiralOrder(const vector<vector<int> > &A) 
{
    int rows, cols, si, sj, maxi, maxj, k, sz, i, j ;
    rows = A.size () ; cols = A[0].size () ;
    sz = rows * cols ;
    
    if (rows == 1)
    {
        /*
        for (int i = 0 ; i < A[0].size () ; i++)
            printf ("%d ", A[0][i]) ;
        */
        return A[0] ;
    }
    
    vector<int> ans ;
    if (cols == 1)
    {
        for (int i = 0 ; i < A.size () ; i++)
        {
            //printf ("%d ", A[i][0]) ;
            ans.push_back (A[i][0]) ;
        }
        return ans ;
    }
    
    k = 0 ;
    maxi = rows - 1 ; maxj = cols - 1 ;
    si = 0 ; sj = 0 ;
    while (1)
    {
        for (j = sj ; j < maxj ; j++, k++)
        {
            ans.push_back (A[si][j]) ;
            //printf ("%d ", A[si][j]) ;
        }
            
        for (i = si ; i < maxi ; i++, k++)
        {
            ans.push_back (A[i][maxj]) ;
            //printf ("%d ", A[i][maxj]) ;
        }
            
        for (j = maxi ; j > sj ; j--, k++) 
        {
            ans.push_back (A[maxi][j]) ;
            //printf ("%d ", A[maxi][j]) ;
        }
            
        for (i = maxi ; i > si ; i--, k++)
        {
            ans.push_back (A[i][sj]) ;
            //printf ("%d ", A[i][sj]) ;
        }
        
        si++ ; sj++ ;
        maxi-- ; maxj-- ;
        if (k == sz)
            break ;
    }
    
    return ans ;
}

