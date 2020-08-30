int rightView (TreeNode *root, int push, vector<int> &ans)
{
    if (!root)
        return 0 ;
        
    if (push == 0)
        ans.push_back (root->val) ;
        
    int hr, hl ;
    hr = rightView (root->right, push > 0 ? push-1 : 0, ans) ;
    hl = rightView (root->left, max(push-1, hr), ans) ;
    
    return max (hl, hr) + 1 ;
}

vector<int> Solution::solve(TreeNode* A) 
{
    if (!A)
        return vector<int> () ;
        
    vector<int> ans ;
    rightView (A, 0, ans) ;
    
    return ans ;
}
