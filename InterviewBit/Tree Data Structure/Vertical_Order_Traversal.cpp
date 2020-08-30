vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) 
{
    int mindist, maxdist, dist ;
    TreeNode *node ;
    vector<pair<TreeNode*,int>> lev, nexlev ;
    pair<TreeNode*,int> p ;
    unordered_map<int,vector<int>> m ;
    
    nexlev.push_back (make_pair (A, 0)) ;
    m[0] = vector<int> () ;
    m[0].push_back (A->val) ;
    mindist = maxdist = 0 ;
    do
    {
        lev = nexlev ;
        nexlev.clear () ;
        for (int i = 0 ; i < (int)lev.size() ; i++)
        {
            p = lev[i] ;
            node = p.first ;
            dist = p.second ;
            
            if (node->left)
            {
                if (m.find(dist - 1) == m.end())
                {
                    if (dist - 1 < mindist)
                        mindist = dist - 1 ;
                    m[dist - 1] = vector<int> () ;
                }
                    
                m[dist - 1].push_back (node->left->val) ;
                nexlev.push_back (make_pair (node->left, dist - 1)) ;
            }
            
            if (node->right)
            {
                if (m.find (dist + 1) == m.end())
                {
                    if (dist + 1 > maxdist)
                        maxdist = dist + 1 ;
                    m[dist + 1] = vector<int> () ;
                }
                    
                m[dist + 1].push_back (node->right->val) ;
                nexlev.push_back (make_pair (node->right, dist + 1)) ;
            }
        }
        
    } while (nexlev.size()) ;
    
    int k ;
    vector<int> vec ;
    vector<vector<int>> ans (maxdist - mindist + 1, vector<int> ()) ;
    k = 0 ;
    for (int j = mindist ; j <= maxdist ; j++, k++)
    {
        if (m.find (j) == m.end())
            continue ;
        
        vec = m[j] ;   
        for (int i = 0 ; i < (int)vec.size() ; i++)
            ans[k].push_back (vec[i]) ;
    }
    
    return ans ;
}

