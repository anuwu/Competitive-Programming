void printmat (vector<vector<int>> &A)
{
    int i, j ;
    for (i = 0 ; i < A.size () ; i++)
    {
        for (j = 0 ; j < A.size () ; j++)
            printf ("%d ", A[i][j]) ;
        printf ("\n") ;
    }
}

void Solution::rotate(vector<vector<int> > &A)
{
    if (A.size () == 1)
        return ;
        
    int org, tmp ;
    int si1, sj1, si2, sj2, lim, k ;
    
    lim = A.size () ;
    for (org = 0 ; org < A.size ()/2 ; org++)
    {
        /*
        
        ---->
        |   |
        |   |
        ----v
        
        */
        si1 = org ; sj1 = org ;
        si2 = org ; sj2 = org + lim - 1 ;
        for (k = 0 ; k < lim - 1 ; k++)
        {
            tmp = A[si1][sj1 + k] ;
            A[si1][sj1 + k] = A[si2 + k][sj2] ;
            A[si2 + k][sj2] = tmp ;
        }
        
        
        /*
        
        ^----
        |   |
        |   |
        <----
        
        */
        si1 = org + lim - 1 ; sj1 = org + lim - 1 ;
        si2 = org + lim - 1 ; sj2 = org ;
        for (k = 0 ; k < lim - 1 ; k++)
        {
            tmp = A[si1][sj1 - k] ;
            A[si1][sj1 - k] = A[si2 - k][sj2] ;
            A[si2 - k][sj2] = tmp ;
        }
        
        
        /*
        
        ---->
        |   |
        |   |
        <----
        
        */
        
        si1 = org + lim - 1 ; sj1 = org + lim - 1 ;
        si2 = org ; sj2 = org ;
        for (k = 0 ; k < lim - 1 ; k++)
        {
            tmp = A[si1][sj1 - k] ;
            A[si1][sj1 - k] = A[si2][sj2 + k] ;
            A[si2][sj2 + k] = tmp ;
        }
        
        lim -= 2 ;
    }
}
