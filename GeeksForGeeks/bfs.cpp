vector <int> bfs(vector<int> g[], int N) 
{
    
    int i, node ;
    queue<int> q ;
    vector<bool> visited (N, false) ;
    vector<int> ans ;
    
    q.push (0) ;
    visited[0] = true ;
    while (!q.empty ())
    {
        node = q.front () ;
        q.pop () ;
        ans.push_back (node) ;
        for (i = 0 ; i < g[node].size() ; i++)
        {
            if (!visited[g[node][i]])
            {
                q.push (g[node][i]) ;
                visited[g[node][i]] = true ;
            }
        }
    }

    return ans ;
}
