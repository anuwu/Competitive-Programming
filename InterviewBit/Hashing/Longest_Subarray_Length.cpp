int Solution::solve(vector<int> &A) 
{
    int i, sum, len, maxlen, N = A.size() ;
    map<int,int> m ;
    map<int,int>::iterator it ;

    maxlen = INT_MIN ;
    sum = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        sum += (A[i] ? 1 : -1) ;
        A[i] = sum ;
        
        if (sum > 0 && i+1 > maxlen)
            maxlen = i+1 ;

        if (m.find (sum) == m.end ())
            m[sum] = i ;
        
        it = m.find (sum) ;
        len = INT_MIN ;
        if (it != m.begin ())
        {
            for (--it ; it != m.begin() ; it = prev(it))
            {
                if (sum - it->first > 1 && i - it->second > len)
                    len = i - it->second ;
            }
        }
        it = m.begin() ;
        if (sum - it->first > 1 && i - it->second > len)
            len = i - it->second ;
            
        if (len > maxlen)
            maxlen = len ;
    }
    
    return maxlen ;
}
