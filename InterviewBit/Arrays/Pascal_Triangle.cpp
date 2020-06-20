vector<vector<int> > Solution::solve(int A) 
{
    int i, j ;
    vector<int> row ;
    vector<vector<int>> pascal ;
    
    if (A == 0) return pascal ;
    
    row.push_back (1) ;
    pascal.push_back (row) ;
    row.clear () ;
    for (i = 1 ; i < A ; i++)
    {
        row.push_back (1) ;
        for (j = 0 ; j < pascal[i-1].size() -1 ; j++)
            row.push_back (pascal[i-1][j] + pascal[i-1][j+1]) ;
        row.push_back (1) ;
        
        pascal.push_back (row) ;
        row.clear () ;
    }
    
    return pascal ;
}
