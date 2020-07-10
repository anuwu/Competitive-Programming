int Solution::solve(int A, vector<vector<int>> &B) 
{
    typedef enum _nodestat
    {
        UN, VIS, TED 
    } nodestat ;
    
    int i, u, v, entry, node ;
    unordered_map<int, vector<int>> adj ;
    stack<pair<int,int>> s ;
    pair<int,int> p ;
    vector<nodestat> vis (A+1, UN) ;
    
    for (i = 0 ; i < B.size() ; i++)
    {
        u = B[i][0] ;
        v = B[i][1] ;
        
        if (adj.find(u) == adj.end())
            adj[u] = vector<int> () ;
        adj[u].push_back (v) ;
    }
    
    entry = 1 ;
    do
    {
        s.push (make_pair (entry, 0)) ;
        
        while (!s.empty ())
        {
            p = s.top() ;
            node = p.first ;
            i = p.second ;
            vis[node] = VIS ;
            
            while (i != adj[node].size() && vis[adj[node][i]] == TED)
                i++ ;
                
            if (i == adj[node].size ())
            {
                vis[node] = TED ;
                s.pop() ;
            }
            else if (vis[adj[node][i]] == VIS)
                return 1 ;
            else
            {
                s.top().second = i ;
                s.push (make_pair (adj[node][i], 0)) ;
            }
        }
        
        while (entry <= A && vis[entry] != UN)
            entry++ ;
    } while (entry <= A) ;
    
    
    return 0 ;
}