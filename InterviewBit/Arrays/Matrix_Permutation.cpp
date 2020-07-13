string Solution::solve(vector<vector<int> > &A) 
{
    int i, j, N = A.size() ;
    string str, strRow ;
    
    for (j = 0 ; j < N ; j++)
        str.append (to_string (A[0][j])) ;
        
    str.append (str) ;

    for (i = 1 ; i < N ; i++)
    {
        strRow.clear() ;
        for (j = 0 ; j < N ; j++)
            strRow.append (to_string (A[i][j])) ;
            
        if (str.find (strRow) == string::npos)
            return "NO" ;
    }
        
    return "YES" ;
}

