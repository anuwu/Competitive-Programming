int makeAnagram(string a, string b) 
{
    int i, cnt, la = a.length(), lb = b.length() ;
    unordered_map<char,int> ma, mb ;

    for (i = 0 ; i < la ; i++)
        if (ma.find (a[i]) == ma.end())
            ma[a[i]] = 1 ;
        else
            ma[a[i]]++ ;

    for (i = 0 ; i < lb ; i++)
        if (mb.find (b[i]) == mb.end())
            mb[b[i]] = 1 ;
        else
            mb[b[i]]++ ;

    cnt = 0 ;
    for (auto it = ma.begin() ; it != ma.end() ; it++)
        if (mb.find (it->first) == mb.end())
            cnt += it->second ;
        else
            cnt += abs (it->second - mb.find(it->first)->second) ;
    

    for (auto it = mb.begin() ; it != mb.end () ; it++)
        if (ma.find (it->first) == mb.end())
            cnt += it->second ;


    return cnt ;
}
