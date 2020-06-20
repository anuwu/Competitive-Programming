void getSum (TreeNode *root, int sum, vector<TreeNode*> path, vector<vector<TreeNode*>> *pathList)
{
    if (!root)
        return ;
    else if (!root->left && !root->right)
    {
        if (root->val == sum) 
        {
            path.push_back (root) ;
            (*pathList).push_back (path) ;
            path.clear () ;
        }
        
        return ;
    }
    
    path.push_back (root) ;
    getSum (root->left, sum - root->val, path, pathList) ;
    getSum (root->right, sum - root->val, path, pathList) ;
}
 

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    vector<vector<TreeNode*>> pathList ;
    vector<TreeNode*> path ;
    
    vector<vector<int>> valpathList ;
    vector<int> valpath ;
    
    getSum (A, B, path, &pathList) ;
    
    int i, j ;
    for (i = 0 ; i < pathList.size () ; i++)
    {
        for (j = 0 ; j < pathList[i].size () ; j++)
            valpath.push_back (pathList[i][j]->val) ;
            
        valpathList.push_back (valpath) ;
        valpath.clear () ;
    }
    
    return valpathList ;
}
