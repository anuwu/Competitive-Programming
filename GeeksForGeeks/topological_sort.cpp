typedef enum _nodestat
{
    UN, VIS, TED
} nodestat ;

vector<int> l ;
vector<nodestat> vis ;
vector<int> *adjc ;

void topo (int u)
{
    int i, v ;
    vis[u] = VIS ;
    
    for (i = 0 ; i < adjc[u].size() ; i++)
    {
        v = adjc[u][i] ;
        
        if (vis[v] == UN)
            topo (v) ;
    }
    
    vis[u] = TED ;
    l.push_back (u) ;
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    l.clear () ;
    vis = vector<nodestat> (V, UN) ;
    
    int entry ;
    adjc = adj ;
    
    entry = 0 ;
    do
    {
        topo (entry) ;
        do entry++ ; while (vis[entry] != UN) ;
    } while (entry < V) ;
    
    vector<int> list (l) ;
    reverse (list.begin(), list.end ()) ;
    
    return list ;
}
