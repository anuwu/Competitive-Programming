vector<int> primeFactors (int n)
{
    int i ;
    vector<int> pf ;
    
    if (n == 2)
    {
        pf.push_back (2) ;
        return pf ;
    }
    
    if (n % 2 == 0)
        pf.push_back (2) ;
        
    while (n % 2 == 0)
        n /= 2 ;
        
    i = 3 ;
    while (i*i <= n)
    {
        if (n % i == 0)
        {
            pf.push_back (i) ;
            while (n % i == 0)
                n /= i ;
        }
            
        i += 2 ;
    }
    
    if (n != 1)
        pf.push_back (n) ;
    
    return pf ;
}

int Solution::solve(vector<int> &A, int B) 
{
    if (B == 1)
        return 0 ;
    
    int i, cnt, N = A.size() ;
    unordered_set<int> s ;
    vector<int> pf ;
    
    for (i = 0 ; i < N ; i++)
        s.insert (A[i]) ;
      
        
    pf = primeFactors (B) ;
    cnt = 0 ;
    

    for (i = 0 ; i < pf.size () ; i++)
        if (s.find (pf[i]) != s.end())
            cnt++ ;
    
    return cnt ;
}

