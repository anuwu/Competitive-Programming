vector <int> dfs(vector<int> g[], int N)
{
    typedef enum _nodestat
    {
        UN, VIS, TED
    } nodestat ;
    
    int i, node ;
    vector<nodestat> vis (N, UN) ;
    stack<pair<int,int>> st ;
    pair<int,int> p ;
    vector<int> ans ;

    node = 0 ;
    st.push (make_pair (0, 0)) ;
    ans.push_back (0) ;
    while (!st.empty ())
    {
        p = st.top() ;
        node = p.first ;
        i = p.second ;
        vis[node] = VIS ;
        
        while (i < g[node].size() && vis[g[node][i]] != UN)
            i++ ;
            
        if (i == g[node].size())
        {
            vis[node] = TED ;
            st.pop () ;
        }
        else
        {
            st.top().second = i ;
            st.push (make_pair (g[node][i], 0)) ;
            ans.push_back (g[node][i]) ;
        }
    }
    
    return ans ;
}
