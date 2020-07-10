bool isCyclic(int V, vector<int> g[])
{
    typedef enum _nodestat
    {
        UN, VIS, TED
    } nodestat ;
    
    int i, node, entry, nextnode ;
    stack<pair<int,int>> st ;
    pair<int,int> p ;
    vector<nodestat> vis (V, UN) ;
    
    entry = 0 ;
    do
    {
        st.push (make_pair (entry, 0)) ;
        vis[entry] = VIS ;
        
        while (!st.empty ())
        {
            p = st.top () ;
            node = p.first ;
            i = p.second ;
            
            while (i < g[node].size() && vis[g[node][i]] == TED)
                i++ ;
                
            if (i == g[node].size ())
            {
                vis[node] = TED ;
                st.pop () ;
            }
            else if (vis[g[node][i]] == VIS)
                return true ;
            else
            {
                st.top().second = i ;
                st.push (make_pair (g[node][i], 0)) ;
                vis[g[node][i]] = VIS ;
            }
        }
        
        while (entry < V && vis[entry] == TED)
            entry++ ;
        
    } while (entry != V) ;

    return false ;    
}
