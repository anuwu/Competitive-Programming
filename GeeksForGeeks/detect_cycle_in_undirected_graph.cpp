bool isCyclic(vector<int> g[], int V)
{
    typedef enum _nodestat
    {
        UN, VIS, TED
    } nodestat ;
   
    int entry, prevnode, node, i ;
    stack<vector<int>> st ;
    vector<int> stvec ;
    vector<nodestat> vis (V, UN) ;
    
    entry = 0 ;
    do
    {
        stvec.clear () ;
        stvec.push_back (entry) ; stvec.push_back (0) ; stvec.push_back (-1) ;
        st.push (stvec) ;
        vis[entry] = VIS ;
       
        while (!st.empty ())
        {
            stvec = st.top() ;
            node = stvec[0] ;
            i = stvec[1] ;
            prevnode = stvec[2] ;
            
           
            while (i < g[node].size())
            {
                if (vis[g[node][i]] == TED || (g[node][i] == prevnode && vis[g[node][i]] == VIS))
                    i++ ;
                else
                    break ;
            }
                
            if (i == g[node].size ())
            {
                vis[node] = TED ;
                st.pop () ;
            }
            else if (vis[g[node][i]] == VIS)
                return true ;
            else
            {
                st.top()[1] = i ;
                
                stvec.clear () ;
                stvec.push_back (g[node][i]) ;
                stvec.push_back (0) ;
                stvec.push_back (node) ;
                st.push (stvec) ;
                
                vis[g[node][i]] = VIS ;
            }
        }
        
        while (entry < V && vis[entry] != UN)
            entry++ ;
       
    } while (entry < V) ;
    
    return false ;
}
