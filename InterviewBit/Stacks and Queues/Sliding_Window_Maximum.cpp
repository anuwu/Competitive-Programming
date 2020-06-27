vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{
    int winst, winend, i, N = A.size () ;
    map<int, int, greater<int>> m ;
    map<int,int>::iterator itr ;
    vector<int> ans ;
    
    for (i = 0 ; i < B ; i++)
    {
        if (m.find (A[i]) == m.end())
            m[A[i]] = 1 ;
        else
            m[A[i]]++ ;
    }
    
    ans.push_back (m.begin()->first) ;
    winst = 1 ;
    winend = B ;
    while (winend < N)
    {
        if (A[winend] != A[winst - 1])
        {
            if (m[A[winst - 1]] == 1)
                m.erase (m.find (A[winst - 1])) ;
            else
                m[A[winst - 1]]-- ;
                
            if (m.find (A[winend]) == m.end())
                m[A[winend]] = 1 ;
            else
                m[A[winend]]++ ;
        }
        ans.push_back (m.begin()->first) ;
            
        winst++ ;
        winend++ ;
    }
    
    return ans ;
}
