
int Solution::colorful(int A) 
{
    int i, j, dig, tmp, cont ;
    long long prod, subprod1, subprod2 ;
    vector<int> digs ;
    vector<long long> lev, nexlev ;
    unordered_set<long long> s ;
    set<pair<int,int>> ps ;
    pair<int,int> digind ;
    
    prod = 1 ;
    tmp = A ;
    while (tmp)
    {
        dig = tmp % 10 ;
        if (dig == 0)
            return 0 ;
        digs.push_back (dig) ;
        prod *= dig ;
        tmp /= 10 ;
    }
    
    reverse (digs.begin(), digs.end()) ;
    s.insert (prod) ;
    ps.insert (make_pair (0, digs.size() - 1)) ;
    nexlev.push_back (prod) ;
    
    cont = digs.size() - 1 ;
    while (cont > 0)
    {
        lev = nexlev ;
        nexlev.clear () ;
        for (i = 0, j = 0 ; i < lev.size() ; i++, j++)
        {
            digind = make_pair (i, i+cont-1) ;
            if (ps.find (digind) == ps.end ())
            {
                subprod1 = lev[i]/digs[i+cont] ;
                if (s.find (subprod1) != s.end ())
                    return 0 ;
                    
                s.insert (subprod1) ;   
                nexlev.push_back (subprod1) ;
                ps.insert (digind) ;
            }
            
            digind = make_pair (i+1, i+cont) ;
            if (ps.find (digind) == ps.end ())
            {
                subprod2 = lev[i]/digs[i] ;
                if (s.find (subprod2) != s.end ())
                    return 0 ;
                    
                s.insert (subprod2) ;   
                nexlev.push_back (subprod2) ;
                ps.insert (digind) ;
            }
        }
        cont-- ;
    }
    
    
    return 1 ;
}

