typedef enum _nodestat
{
    UN, VIS, TED
} nodestat ;

class Solution 
{
public:    
    
    bool dfsCyc (int node, vector<vector<int>> &adj, vector<nodestat> &vis)
    {
        vis[node] = VIS ;
        
        for (int i = 0 ; i < adj[node].size() ; i++)
            if (vis[adj[node][i]] == VIS || (vis[adj[node][i]] == UN && dfsCyc (adj[node][i], adj, vis)))
                return true ;
        
        vis[node] = TED ;
        return false ;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int seed, i, M = prerequisites.size() ;
        bool cycle ;
        vector<vector<int>> adj (numCourses, vector<int> ()) ;
        vector<nodestat> vis (numCourses, UN) ;
        
        for (i = 0 ; i < M ; i++)
            adj[prerequisites[i][0]].push_back (prerequisites[i][1]) ;
        
        seed = 0 ;
        cycle = false ;
        do
        {
            cycle = dfsCyc (seed, adj, vis) ;
            if (cycle)
                return false ;
            
            do seed++ ; while (seed < numCourses && vis[seed] != UN) ;
        } while (seed < numCourses) ;
        
        return true ;
    }
};
