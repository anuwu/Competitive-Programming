void preOrder (TreeNode* node, int d, unordered_map<int,vector<int>> &m, int &mind)
{
    if (!node)
        return ;
        
    if (d < mind)
        mind = d ;
        
    if (m.find(d) == m.end())
        m[d] = vector<int> () ;
        
    m[d].push_back (node->val) ;
    preOrder (node->left, d-1, m, mind) ;
    preOrder (node->right, d, m, mind) ;
}


vector<int> Solution::solve(TreeNode* A) 
{
    if (!A)
        return vector<int> () ;
    
    int d, mind ;
    vector<int> ans, vec ;
    unordered_map<int,vector<int>> m ;
    
    mind = 0 ;
    preOrder (A, 0, m, mind) ;
    
    for (d = 0 ; d >= mind ; d--)
    {
        vec = m[d] ;
        for (int i = 0 ; i < (int)vec.size() ; i++)
            ans.push_back (vec[i]) ;
    }
    
    return ans ;
}



