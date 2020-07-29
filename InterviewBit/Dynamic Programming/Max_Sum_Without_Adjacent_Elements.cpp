int Solution::adjacent(vector<vector<int> > &A) 
{
    int i, incl, excl, tmpincl, N = A[0].size() ;
    
    incl = max (A[0][0], A[1][0]) ;
    excl = 0 ;
    for (i = 1 ; i < N ; i++)
    {
        tmpincl = excl + max (A[0][i], A[1][i]) ; ;
        excl = max (excl, incl) ;
        incl = tmpincl ;
    }
    
    return excl > incl ? excl : incl ;
}

