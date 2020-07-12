vector<int> ansPath ;

bool getPath (TreeNode* root, int target, vector<int> currPath)
{
    if (root == NULL)
        return false ;
    
    currPath.push_back (root->val) ;
    
    if (root->val == target)
    {
        ansPath = currPath ;
        return true ;
    }
    else
    {
        bool leftPath, rightPath ;
        leftPath = rightPath = false ;
        
        leftPath = getPath (root->left, target, currPath) ;
        rightPath = getPath (root->right, target, currPath) ;
        
        return leftPath || rightPath ;
    }
}

vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int> currPath ;
    ansPath.clear () ;
    getPath (A, B, currPath) ;
    return ansPath ;
}

