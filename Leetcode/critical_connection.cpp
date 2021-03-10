class Solution {
public:
    unordered_set<int> dfs (int u, int pi, unordered_set<int> &ancestors, vector<bool> &vis, vector<vector<int>> &adj, vector<vector<int>> &crit)
    {
        int v ;
        vis[u] = true ;
        ancestors.insert(u) ;
        unordered_set<int> my_back, neigh_back ;
        
        
        printf("pi = %d, Ancestors of %d -> ", pi, u) ;
        for (auto it = ancestors.begin() ; it != ancestors.end() ; it++)
            printf("%d, ", *it) ;
        printf("\n") ;
        
        
        for (int i = 0 ; i < adj[u].size() ; i++)
        {
            v = adj[u][i] ;
            if (vis[v])
            {
                if (ancestors.find(v) != ancestors.end() && v != pi)
                    my_back.insert(v) ;
            }
            else
            {
                neigh_back = dfs(v, u, ancestors, vis, adj, crit) ;
                ancestors.erase(ancestors.find(v)) ;
                bool is_crit = true ;
                for (auto it = neigh_back.begin() ; it != neigh_back.end() ; it++)
                {
                    my_back.insert(*it) ;
                    if (ancestors.find(*it) != ancestors.end())
                        is_crit = false ;
                }
                
                if (is_crit)
                {
                    vector<int> cri {u, v} ;
                    crit.push_back(cri) ;
                }
            }
        }
        
        
        printf("Back of %d -> ", u) ;
        for (auto it = my_back.begin() ; it != my_back.end() ; it++)
            printf("%d, ", *it) ;
        printf("\n") ;
        
        
        return my_back ;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        int i, j, u, v, seed ;
        vector<vector<int>> crit ;
        vector<vector<int>> adj(n, vector<int> ()) ;
        vector<bool> vis(n, false) ;
        
        for (i = 0 ; i < connections.size() ; i++)
        {
            u = connections[i][0] ;
            v = connections[i][1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }
        
        seed = 0 ;
        do
        {
            unordered_set<int> ancestors ;
            dfs(seed, -1, ancestors, vis, adj, crit) ;
            do seed++ ; while (seed < n && vis[seed]) ;
        } while (seed < n) ;
        
        return crit ;
    }
};
