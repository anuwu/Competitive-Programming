vector<int> Solution::nextGreater(vector<int> &A) 
{
    int i, N = A.size() ;
    vector<int> ans (N, -1) ;
    stack<pair<int,int>> s ;
    pair<int,int> p ;
    
    s.push (make_pair (A[0], 0)) ;
    for (i = 1 ; i < N ; i++)
    {
        if (A[i] > s.top().first)
        {
            while (!s.empty () && A[i] > s.top().first)
            {
                ans[s.top().second] = A[i] ;
                s.pop () ;
            }
        }
        
        s.push (make_pair (A[i], i)) ;
    }
    
    return ans ;
}

