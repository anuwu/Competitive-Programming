int alternatingCharacters(string s) 
{
    int i, cnt, l = s.length() ;

    cnt = 0 ;
    for (i = 1 ; i < l ; i++)
        if (s[i] == s[i-1])
            cnt++ ;

    
    return cnt ;
}
