class Solution {
public:
    
    int maxpath (TreeNode *root, int* maxsum)
    {
        if (!root)
            return 0 ;
        
        int l, r, maxone, maxtop ;
        l = maxpath (root->left, maxsum) ;
        r = maxpath (root->right, maxsum) ;
        
        maxone = max (max (l, r) + root->val, root->val) ;
        maxtop = max (maxone, l + r + root->val) ;
        
        *maxsum = max (*maxsum, maxtop) ;
            
        return maxone ;
        
    }
    
    int maxPathSum(TreeNode* root) 
    {
        if (!root)
            return 0 ;
        
        int maxsum = INT_MIN ;
        maxpath (root, &maxsum) ;
        
        return maxsum ;
    }
};
