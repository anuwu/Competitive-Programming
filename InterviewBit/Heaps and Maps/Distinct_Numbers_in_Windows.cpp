vector<int> Solution::dNums(vector<int> &A, int B) 
{
    int winst, winend, uniq, N = A.size () ; 
    vector<int> ans ;
    map<int, int> s ;
    
    if (B > A.size ())
        return ans ;
    if (B == 1)
    {
        ans = vector<int> (N, 1) ;
        return ans ;
    }
        
    for (int i = 0 ; i < B ; i++)
    {
        if (s.find (A[i]) == s.end ())
            s[A[i]] = 1 ;
        else
            s[A[i]]++ ;
    }
        
    winst = 1 ;
    winend = B ;
    ans.push_back (s.size ()) ;
    while (winend < N)
    {
        if (s[A[winst - 1]] == 1)
            s.erase (s.find (A[winst - 1])) ;
        else
            s[A[winst - 1]]-- ;
            
        if (s.find (A[winend]) == s.end ())
            s[A[winend]] = 1 ;
        else
            s[A[winend]]++ ;
            
        ans.push_back (s.size ()) ;
        winst++ ;
        winend++ ;
    }
    
    return ans ;
}
