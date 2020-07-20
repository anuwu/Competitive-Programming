vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int cnt, i, j, N = A.size() ;
    priority_queue <pair<int, pair<int,int>>> pq ;
    set <pair<int,int>> s ;
    pair<int, pair<int,int>> pqp ;
    pair<int,int> p1, p2 ;
    vector<int> ans ;
    
    sort (A.begin(), A.end()) ;
    sort (B.begin(), B.end()) ;
    i = j = N-1 ;
    pq.push (make_pair (A[i] + B[j], make_pair (i, j))) ;
    s.insert (make_pair (i, j)) ;
    
    cnt = 0 ;
    do
    {
        pqp = pq.top () ;
        pq.pop () ;
        
        ans.push_back (pqp.first) ;
        cnt++ ;
        
        if (cnt == C)
            break ;
        
        p1 = pqp.second ;
        p2 = p1 ;
        
        p1.first-- ;
        if (s.find (p1) == s.end())
        {
            i = p1.first ;
            j = p1.second ;
            
            s.insert (p1) ;
            pq.push (make_pair (A[i] + B[j], make_pair (i, j))) ;
        }
        
        p2.second-- ;
        if (s.find(p2) == s.end())
        {
            i = p2.first ;
            j = p2.second ;
            
            s.insert (p2) ;
            pq.push (make_pair (A[i] + B[j], make_pair (i, j))) ;
        }
    } while (true) ;
    
    return ans ;
}

