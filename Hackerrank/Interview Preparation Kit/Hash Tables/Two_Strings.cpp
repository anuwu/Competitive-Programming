string twoStrings(string s1, string s2) 
{
    int i, l1 = s1.length(), l2 = s2.length() ;
    unordered_set<char> s ;
    string yes = "YES", no = "NO" ;

    for (i = 0 ; i < l1 ; i++)
        if (s.find (s1[i]) == s.end ())
            s.insert (s1[i]) ;

    for (i = 0 ; i < l2 ; i++)
        if (s.find (s2[i]) != s.end())
            return yes ;

    return no ;
}
