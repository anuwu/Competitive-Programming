vector<int> Solution::allFactors(int A) 
{
    vector<int> ans ;
    int i, j ;
    double root = sqrt(A) ;
    
    ans.push_back (1) ;
    if (A == 1)
        return ans ;
        
    for (i = 2 ; i < root ; i++)
        if (A % i == 0) 
            ans.push_back (i) ;
    
    j = ans.size () - 1 ;
    if (i*i == A)
        ans.push_back (i) ; 
    
    for ( ; j >= 0 ; j--)
        ans.push_back (A/ans[j]) ;
        
    return ans ;
}
