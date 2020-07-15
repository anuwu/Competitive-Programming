#define MOD 1000003

vector<long long> fact ;

long long countRank (string &s, map<char,int> &cval)
{
    if (s.length() == 1)
        return 1 ;
    
    long long rank ;
    map<char,int>::iterator it ;
    
    rank = (fact[s.length() - 1] * (cval[s[0]] - 1)) % MOD ;
    cval[s[0]] = -1 ;
    
    it = cval.find (s[0]) ;
    for (it++ ; it != cval.end() ; it++)
    {
        if (it->second > 0)
            it->second-- ;
    }
    
    s.erase (0, 1) ;
    rank = (rank + (countRank (s , cval) % MOD)) % MOD ;
    
    return rank ;
}

int Solution::findRank(string s) 
{
    if (s.length () == 1)
        return 1 ;
        
    fact.clear () ;
    
    int i, len = s.length() ;
    long long rank ;
    string cp (s) ;
    map<char,int> cval ;
    
    fact = vector<long long> (len, 1) ;
    for (i = 2 ; i < len ; i++)
        fact[i] = (fact[i-1] * i) % MOD ;
        
    sort (cp.begin(), cp.end()) ;
    for (i = 0 ; i < cp.length () ; i++)
        cval[cp[i]] = i+1 ;
    
    rank = countRank (s, cval) ;
    
    return rank ;
}

