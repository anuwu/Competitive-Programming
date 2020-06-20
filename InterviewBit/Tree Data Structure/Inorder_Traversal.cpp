#include <bits/stdc++.h>

vector<int> Solution::inorderTraversal(TreeNode* A)
{
    vector<TreeNode*> stack ;
    vector<int> inorder ;
    
    TreeNode *tmp, *pop ;
    
    stack.push_back (A) ;
    tmp = A->left ;
    while (!stack.empty ())
    {
        while (tmp)
        {
            stack.push_back (tmp) ;
            tmp = tmp->left ;
        }
        
        pop = stack.back () ;
        stack.pop_back () ;
        inorder.push_back (pop->val) ;
        
        tmp = pop->right ;
        if (tmp)
        {
            stack.push_back (tmp);
            tmp = tmp->left ;
        }
    }
    
    return inorder ;
}