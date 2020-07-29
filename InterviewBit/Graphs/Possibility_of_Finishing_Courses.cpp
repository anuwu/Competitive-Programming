typedef enum _nodestat
{
    UN, VIS, TED
} nodestat ;

bool dfsCyc (int node, vector<vector<int>> &adj, vector<nodestat> &vis)
{
    vis[node] = VIS ;
    
    for (int i = 0 ; i < adj[node].size() ; i++)
        if (vis[adj[node][i]] == VIS || (vis[adj[node][i]] == UN && dfsCyc (adj[node][i], adj, vis)))
            return true ;
    
    vis[node] = TED ;
    return false ;
}


int Solution::solve(int A, vector<int> &B, vector<int> &C) 
{
    int seed, i, M = B.size() ;
    bool cycle ;
    vector<vector<int>> adj (A, vector<int> ()) ;
    vector<nodestat> vis (A, UN) ;
    
    for (i = 0 ; i < M ; i++)
        adj[B[i] - 1].push_back (C[i] - 1) ;
    
    seed = 0 ;
    cycle = false ;
    do
    {
        cycle = dfsCyc (seed, adj, vis) ;
        if (cycle)
            return 0 ;
        
        do seed++ ; while (seed < A && vis[seed] != UN) ;
    } while (seed < A) ;
    
    return 1 ;
}

