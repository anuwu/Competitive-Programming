class Solution {
public:
    
    bool isIdentical(TreeNode* s, TreeNode* t)
    {
        if (!s && !t)
            return true ;
        else if (s && t)
            return s->val == t->val && isIdentical(s->left, t->left) && isIdentical(s->right, t->right) ;
        else
            return false ;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if (!s)
            return false ;
        
        if (isIdentical(s, t))
            return true ;
        else
            return isSubtree(s->left, t) || isSubtree(s->right, t) ;
    }
};
