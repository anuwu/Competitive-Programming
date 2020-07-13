vector<int> Solution::solve(vector<int> &A, int B) 
{
    if (B < 1)
        B = 1 ;
    
    int l, r, fneg, N = A.size() ;
    vector<int> ans ;
    deque<pair<int,int>> negs ;
    
    for (r = 0 ; r < B ; r++)
        if (A[r] < 0)
            negs.push_back (make_pair(A[r],r)) ;
            
    
    if (negs.size())
        fneg = negs.front().first ;
    else
        fneg = 0 ;
    ans.push_back (fneg) ;
    
    l = 1 ;
    for (; r < N ; r++, l++)
    {
        if (negs.front().second == l-1)
            negs.pop_front () ;
        
        if (A[r] < 0)
            negs.push_back (make_pair (A[r], r)) ;
            
        if (negs.size())
            fneg = negs.front().first ;
        else
            fneg = 0 ;
        ans.push_back (fneg) ;
    }

    return ans ;
}
