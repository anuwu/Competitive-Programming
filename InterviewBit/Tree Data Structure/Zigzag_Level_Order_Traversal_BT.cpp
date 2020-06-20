vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) 
{
    vector<vector<TreeNode*>> lvlorderNode ;
    vector<TreeNode*> lvlNode ;
    vector <vector<int>> lvlorderVal ;
    vector <int> lvlVal ;
    
    TreeNode *tmp = A ;
    int i, j, k ;
    int start, end, incr ;
    lvlNode.push_back (A) ;
    i = 0 ;
    do
    {
        lvlorderNode.push_back (lvlNode) ;
        lvlNode.clear () ;
        
        for (j = 0 ; j < lvlorderNode[i].size () ; j++)
        {
            tmp = lvlorderNode[i][j] ;
            if (tmp->left) lvlNode.push_back (tmp->left) ;
            if (tmp->right) lvlNode.push_back (tmp->right) ;
        }

        i++ ;
    } while (!lvlNode.empty ()) ;
    
    for (k = 0 ; k < i ; k++)
    {
        start = 0 ;
        end = lvlorderNode[k].size () ;
        incr = 1 ;
        if (k % 2)
        {
            start = end - 1 ;
            end = -1 ;
            incr = -1 ;
        }
        
        lvlVal.clear () ;
        for ( ; start != end ; start += incr)
            lvlVal.push_back (lvlorderNode[k][start]->val) ;
    
        lvlorderVal.push_back (lvlVal) ;
    }
    
    return lvlorderVal ;
}
