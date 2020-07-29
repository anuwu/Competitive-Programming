
typedef enum _nodestat
{
    UN, VIS, TED
} nodestat ;

vector<vector<int>> adj ;
vector<nodestat> vis ;

void dfs (int node)
{
    vis[node] = VIS ;
    
    for (int i = 0 ; i < adj[node].size() ; i++)
    {
        if (vis[adj[node][i]] == UN)
            dfs (adj[node][i]) ;
    }
    
    vis[node] = TED ;
}


int Solution::solve(int A, vector<vector<int> > &B) 
{
    adj.clear () ;
    vis.clear () ;
    
    int i, edgelist = B.size() ;
    vis = vector<nodestat> (A+1, UN) ;
    adj = vector<vector<int>> (A+1, vector<int> ()) ;
    
    for (i = 0 ; i < edgelist ; i++)
        adj[B[i][0]].push_back (B[i][1]) ;
        
    
    dfs (1) ;
    if (vis[A] != TED)
        return 0 ;
    else
        return 1 ;
}

