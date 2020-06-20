vector<vector<int> > Solution::prettyPrint(int A) 
{
    if (A == 1)
    {
        vector<vector<int>> mat ;
        vector<int> row ;
        row.push_back (1) ;
        mat.push_back (row) ;
        return mat ;
    }
    
    vector<vector<int>> mat(A, vector<int> (A, 0)); 

    int i, j, rows, midi, k, l ;
    rows = 2*A - 1 ; midi = A - 1 ;
    

    for (i = 0 ; i < midi ; i++)
    {
        for (j = 0 ; j < i ; j++)
        {
            mat[i][j] = A - j ;
            mat[i][rows-j-1] = mat[i][j] ;
            mat[rows-i-1][j] = mat[i][j] ;
            mat[rows-i-1][rows-j-1] = mat[i][j] ;
        }
        
        for ( ; j < midi ; j++)
        {
            mat[i][j] = A - i ;
            mat[i][rows-j-1] = mat[i][j] ;
            mat[rows-i-1][j] = mat[i][j] ;
            mat[rows-i-1][rows-j-1] = mat[i][j] ;
        }
        
        for (k = 0 ; k < rows ; k++)
        {
            for (l = 0 ; l < rows ; l++)
                printf ("%d ", mat[k][l]) ;
            printf ("\n") ;
        }
        
        break ;
    }
    
    return mat ;
}
