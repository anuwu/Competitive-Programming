string isValid(string s) 
{
    int i, l = s.length() ;
    string yes ("YES"), no ("NO") ;
    unordered_map<char,int> m ;
    unordered_map<int,int> freq ;

    for (i = 0 ; i < l ; i++)
        if (m.find (s[i]) == m.end())
            m[s[i]] = 1 ;
        else
            m[s[i]]++ ;

    for (auto it = m.begin() ; it != m.end() ; it++)
        if (freq.find (it->second) == freq.end())
            freq[it->second] = 1 ;
        else
            freq[it->second]++ ;

    if ((int)freq.size() == 1)
        return yes ;
    else if ((int)freq.size() == 2)
    {
        int f1, f2, c1, c2 ;
        auto it = freq.begin() ;

        f1 = it->first ;
        c1 = it->second ;
        it++ ;
        f2 = it->first ;
        c2 = it->second ;

        if (((f1 == 1 && c1 == 1) || (f1 == f2 - 1 && c2 == 1)) || ((f2 == 1 && c2 == 1) || (f2 == f1 - 1 && c1 == 1 )))
            return yes ;
    }
    
    return no ;
}
