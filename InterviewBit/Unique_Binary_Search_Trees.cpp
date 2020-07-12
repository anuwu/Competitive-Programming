

TreeNode* newNode (int val)
{
    TreeNode *tmp ;
    
    tmp = (TreeNode*) malloc (sizeof (TreeNode)) ;
    tmp->val = val ;
    tmp->left = NULL ;
    tmp->right = NULL ;
    
    return tmp ;
}



vector<TreeNode*> genTrees (int low, int high)
{
    int i, j, k ;
    TreeNode *root ;
    vector<TreeNode*> fin, genl, genr ;
    
    if (low == high)
    {
        root = newNode (low) ;
        fin.push_back (root) ;
        return fin ;
    }

    genl = genTrees (low + 1, high) ;
    for (i = 0 ; i < genl.size() ; i++)
    {
        root = newNode (low) ;
        root->right = genl[i] ;
        fin.push_back (root) ;
    }
    
    for (i = low + 1 ; i < high ; i++)
    {
        genl = genTrees (low, i - 1) ;
        genr = genTrees (i+1, high) ;
        
        for (j = 0 ; j < genl.size() ; j++)
        {
            for (k = 0 ; k < genr.size() ; k++)
            {
                root = newNode (i) ;
                root->left = genl[j] ;
                root->right = genr[k] ;
                fin.push_back (root) ;
            }
        }
    }
    
    genr = genTrees (low, high - 1) ;
    for (i = 0 ; i < genr.size() ; i++)
    {
        root = newNode (high) ;
        root->left = genr[i] ;
        fin.push_back (root) ;
    }
    
    return fin ;
}


vector<TreeNode*> Solution::generateTrees(int A) 
{
    int i ;
    vector<TreeNode*> ans ;
    
    return genTrees (1, A) ;
}

