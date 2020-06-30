int Solution::longestConsecutive(const vector<int> &A) 
{
    int i, j, num, len, maxlen, N = A.size () ;
    unordered_map <int, bool> m ;
    
    for (i = 0 ; i < N ; i++)
        m[A[i]] = false ;
        
    maxlen = 1 ;
    for (i = 0 ; i < N ; i++)
    {
        num = A[i] ;
        if (m[num])
            continue ;
            
        m[num] = true ;
        len = 1 ;
        j = num + 1 ;
        while (m.find(j) != m.end())
        {
            m[j] = true; 
            len++ ;
            j++ ;
        }
        
        j = num - 1 ;
        while (m.find(j) != m.end())
        {
            m[j] = true ;
            len++ ;
            j-- ;
        }
        
        if (len > maxlen)
            maxlen = len ;
    }
    
    return maxlen ;
}

