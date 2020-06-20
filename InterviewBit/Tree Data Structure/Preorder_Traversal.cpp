vector<int> Solution::preorderTraversal(TreeNode* A) 
{
    vector<TreeNode*> stack ;
    vector<int> preorder ;
    
    TreeNode *tmp, *pop ;
    tmp = A ;
    stack.push_back (tmp) ;
    tmp = tmp->left ;
    while (!stack.empty ())
    {
        pop = stack.back () ;
        stack.pop_back () ;
        
        preorder.push_back (pop->val) ;
        if (pop->right)
            stack.push_back (pop->right) ;
        if (pop->left)
            stack.push_back (pop->left) ;
    }
    
    return preorder ;
}
