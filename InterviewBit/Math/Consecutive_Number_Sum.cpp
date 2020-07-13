int Solution::solve(int A) 
{
    int i, root, cnt, k, f1, f2 ;
    vector<pair<int,int>> fact ;
    
    fact.push_back (make_pair (1, 2*A)) ;
    root = sqrt(2*A) ;
    for (i = 2 ; i <= root ; i++)
    {
        if ((2*A)%i == 0)
            fact.push_back (make_pair (i, (2*A)/i)) ;
    }
    
    cnt = 1 ;
    for (k = 1 ; k < fact.size() ; k++)
    {
        
        f1 = fact[k].first ;
        f2 = fact[k].second ;
        f2 -= (f1 + 1) ;
        if (f2 % 2 == 0)
            cnt++ ;
    }
    
    return cnt ;
}

