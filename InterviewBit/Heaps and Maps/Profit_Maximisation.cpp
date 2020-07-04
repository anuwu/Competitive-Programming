int Solution::solve(vector<int> &A, int B) 
{
    int i, profit, N = A.size() ;
    set<pair<int, int>, greater<pair<int, int>>> s ;
    set<pair<int, int>, greater<pair<int, int>>> ::iterator it ;
    pair<int,int> max ;
    
    for (i = 0 ; i < N ; i++)
        s.insert (make_pair (A[i], i)) ;
    
    profit = 0 ;
    for (i = 0 ; i < B ; i++)
    {
        it = s.begin () ;
        max = *it ;
        profit += max.first ;
        max.first-- ;
        
        s.erase (s.begin ()) ;   
        if (max.first > 0)
            s.insert (max) ;
    }
    
    return profit ;
}


