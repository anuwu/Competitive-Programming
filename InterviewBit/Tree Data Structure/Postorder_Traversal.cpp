vector<int> Solution::postorderTraversal(TreeNode* A) 
{
    vector<TreeNode*> stack1, stack2 ;
    vector<int> postorder ;
    
    TreeNode *tmp ;
    stack1.push_back (A) ;
    
    while (!stack1.empty ())
    {
        tmp = stack1.back () ; stack1.pop_back () ;
        stack2.push_back (tmp) ;
        
        if (tmp->left) stack1.push_back (tmp->left) ;
        if (tmp->right) stack1.push_back (tmp->right) ;
    }
    
    while (!stack2.empty ())
    {
        tmp = stack2.back () ; stack2.pop_back () ;
        postorder.push_back (tmp->val) ;
    }
    
    return postorder ;
}
