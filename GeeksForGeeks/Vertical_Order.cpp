vector<int> verticalOrder(Node *root)
{
    int i, hor ;
    Node *tmp ;
    vector<pair<Node*,int>> lev, nexlev ;
    vector<int> vec, ans ;
    pair<Node*,int> p ;
    map<int,vector<int>> m ;
    
    nexlev.push_back (make_pair (root, 0)) ;
    do
    {
        lev = nexlev ;
        nexlev.clear() ;
        for (i = 0 ; i < (int)lev.size() ; i++)
        {
            p = lev[i] ;
            tmp = p.first ;
            hor = p.second ;
            
            if (tmp->left)
                nexlev.push_back (make_pair (tmp->left, hor-1)) ;
            if (tmp->right)
                nexlev.push_back (make_pair (tmp->right, hor+1)) ;
                
            if (m.find(hor) == m.end())
            {
                vec.clear() ;
                m[hor] = vec ;
            }
            
            m[hor].push_back (tmp->data) ;
        }
        
    } while (nexlev.size()) ;
    
    for (auto it = m.begin() ; it != m.end() ; it++)
    {
        vec = it->second ;
        for (i = 0 ; i < (int)vec.size() ; i++)
            ans.push_back (vec[i]) ;
    }
    
    return ans ;
    
}
