class Solution {
public:
    
    bool isSame (TreeNode* s, TreeNode* t)
    {
        if (!s && !t)
            return true ;
        else if (s && t)
        {
            if (s->val == t->val)
                return isSame (s->left, t->left) && isSame (s->right, t->right) ;
            else
                return false ;
        }
        else
            return false ;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if (!t)
            return true ;
        if (!s)
            return false ;
        
        bool sameTree = isSame (s, t) ;
        if (sameTree)
            return true ;
        
        return isSubtree (s->left, t) || isSubtree (s->right, t) ;
        
    }
};
