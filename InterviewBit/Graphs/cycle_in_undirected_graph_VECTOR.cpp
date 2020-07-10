typedef enum _nodestat
{
    UN, VIS, TED 
} nodestat ;
    
unordered_map<int, vector<int>> adj ;
vector<nodestat> vis ;

bool cycleDfs (int u, int parent)
{
    int i, v ;
    bool cyc ;
    vis[u] = VIS ;
    unordered_set<int>::iterator it ;
    
    for (i = 0 ; i < adj[u].size() ; i++)
    {
        v = adj[u][i] ;
        if (vis[v] == UN)
        {
            cyc = cycleDfs (v, u) ;
            if (cyc)
                return true ;
        }
        else if (vis[v] == VIS && parent != -1 && v != parent)
            return true ;
    }
    
    vis[u] = TED ;
    return false ;
}


int Solution::solve(int A, vector<vector<int>> &B) 
{
    adj.clear () ;
    vis = vector<nodestat> (A+1, UN) ;
    
    int i, u, v, entry ;
    bool cycle ;
    
    for (i = 0 ; i < B.size() ; i++)
    {
        u = B[i][0] ;
        v = B[i][1] ;
        
        if (adj.find(u) == adj.end())
            adj[u] = vector<int> () ;
        adj[u].push_back (v) ;
        
        if (adj.find(v) == adj.end())
            adj[v] = vector<int> () ;
        adj[v].push_back (u) ;
    }
    
    entry = 1 ;
    cycle = false ;
    
    do
    {
        cycle = cycleDfs (entry, -1) ;
        if (cycle)
            return true ;
            
        do entry++ ; while (entry <= A && vis[entry] != UN) ;
    } while (entry <= A) ;
    
    return false ;
}
