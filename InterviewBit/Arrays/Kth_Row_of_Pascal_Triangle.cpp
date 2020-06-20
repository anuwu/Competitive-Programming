long long binomial (int n, int grdr)
{
    long long i, num = 1, fact = 1 ;
    
    i = n ;
    while (i > grdr)
    {
        num *= i ;
        i-- ;
    }
    
    i = n - grdr ;
    while (i >= 1)
    {
        fact *= i ;
        i-- ;
    }
    
    return num/fact ;
}

vector<int> Solution::getRow(int A) 
{
    vector<int> row ;
    row.push_back (1) ;
    
    if (A == 0) return row ;
    int i ;
    for (i = 1 ; i < A  ; i++)
        row.push_back ((int)binomial (A, max(i, A-i))) ;
    
    row.push_back (1) ;
    
    return row ;
}
