int Solution::uniquePaths(int A, int B) 
{
    if (A == 1 || B == 1)
        return 1 ;
        
    vector<vector<int>> mat (A, vector<int> (B, 1)) ;
    
    int i, j ;
    for (i = 1 ; i < A ; i++)
    {
        for (j = 1 ; j < B ; j++)
            mat[i][j] = mat[i][j-1] + mat[i-1][j] ;
    }
    
    return mat[A-1][B-1] ;
}
