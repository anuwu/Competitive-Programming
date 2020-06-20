vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    if (A.size () == 1)
        return A ;
        
    vector<int> diag ;
    vector<vector<int>> diaglist ;
    int i, j, k ;
    
    for (k = 0 ; k < A.size () ; k++)
    {
        i = 0 ; j = k ;
        while (j >= 0)
        {
            diag.push_back (A[i][j]) ;
            i++ ; j-- ;
        }
        
        diaglist.push_back (diag) ;
        diag.clear () ;
    }
    
    for (k = 1 ; k < A.size () ; k++)
    {
        i = k ; j = A.size () - 1 ;
        while (i < A.size ())
        {
            diag.push_back (A[i][j]) ;
            i++ ; j-- ;
        }
        
        diaglist.push_back (diag) ;
        diag.clear () ;
    }
    
    return diaglist ;
}
