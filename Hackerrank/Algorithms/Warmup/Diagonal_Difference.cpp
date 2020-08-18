
int diagonalDifference(vector<vector<int>> arr) 
{
    int i, d1, d2, N = arr.size() ;

    d1 = d2 = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        d1 += arr[i][i] ;
        d2 += arr[i][N-i-1] ;
    }

    return (int)abs(d1 - d2) ;

}
