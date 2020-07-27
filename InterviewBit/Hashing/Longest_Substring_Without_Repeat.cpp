int Solution::lengthOfLongestSubstring(string A) 
{
    if (A.length () == 0)
        return 0 ;
    else if (A.length() == 1)
        return 1 ;
    else if (A.length () == 2)
        return 1 + (A[0] != A[1] ? 1 : 0) ;
    
    int i, j, rep, len, maxlen, N = A.length () ;
    unordered_map<char, int> m ;
    
    maxlen = INT_MIN ;
    i = 0 ;
    for (j = 0 ; j < N ; j++)
    {
        if (m.find (A[j]) != m.end ())
        {
            rep = m[A[j]] ;
            len = j-i ;
            maxlen = max (maxlen, len) ;
            
            for ( ; i <= rep ; i++)
                m.erase (A[i]) ;
        }
        
        m[A[j]] = j ;
    }
    
    len = j-i ;
    maxlen = max (maxlen, len) ;
    if (maxlen == INT_MIN)
        return 1 ;
    return maxlen ;
}

