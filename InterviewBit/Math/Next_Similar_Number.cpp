string Solution::solve(string A) 
{
    int i, j, N, ascbreak ;
    char breakchar ;
    map<char,int> m ;
    map<char,int>::iterator it ;
    string ans ("") ;
    
    ascbreak = -1 ;
    N = A.length () ;
    m[A[N-1]] = 1 ;
    for (i = N-2 ; i >= 0 ; i--)
    {
        if (A[i] < A[i+1])
        {
            ascbreak = i+1 ;
            break ;
        }
        else
        {
            if (m.find (A[i]) == m.end())
                m[A[i]] = 1 ;
            else
                m[A[i]]++ ;
        }
    }
    
    if (ascbreak == -1)
    {
        ans.append ("-1") ;
        return ans ;
    }
    
    for (i = 0 ; i < ascbreak - 1 ; i++)
        ans.push_back (A[i]) ;

    breakchar = A[ascbreak - 1] ;
    if (m.find (breakchar) == m.end ())
        m[breakchar] = 1 ;
    else
        m[breakchar]++ ;
        
    for (it = m.begin () ; it != m.end () ; it++)
    {
        if (it->first > breakchar)
            break ;
    }
    
    ans.push_back (it->first) ;
    it->second-- ;
        
    for (it = m.begin() ; it != m.end() ; it++)
    {
        for (i = 0 ; i < it->second ; i++)
            ans.push_back (it->first) ;
    }
    return ans ;
}