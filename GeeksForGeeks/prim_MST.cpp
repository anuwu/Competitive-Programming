int spanningTree(int V, int E, vector<vector<int>> &graph) 
{
    int i, node, mstSum ;
    unordered_map<int,int> m ;
    set<pair<int,int>> s ;
    set<pair<int,int>>::iterator it ;
    pair<int,int> p, pfind ;
    
    m[0] = 0 ;
    s.insert (make_pair (0, 0)) ;
    for (i = 1 ; i < V ; i++)
    {
        s.insert (make_pair (INT_MAX, i)) ;
        m[i] = INT_MAX ;
    }
        
    mstSum = 0 ;
    while (!s.empty ())
    {
        it = s.begin () ;
        p = *it ;
        s.erase (it) ;
        
        mstSum += p.first ;
        node = p.second ;
        m.erase (m.find (node)) ;
        
        for (i = 0 ; i < V ; i++)
        {
            if (graph[node][i] != INT_MAX && m.find(i) != m.end() && graph[node][i] < m[i])
            {
                pfind = make_pair (m[i], i) ;
                it = s.find (pfind) ;
                s.erase (it) ;
                
                pfind.first = graph[node][i] ;
                s.insert (pfind) ;
                m[i] = graph[node][i] ;
            }
        }
    }
    
    return mstSum ;
}