void Solution::connect(TreeLinkNode* A) 
{
    int i, sz ;
    vector<TreeLinkNode*> level ;
    TreeLinkNode *tmp, *nex ;
    
    level.push_back (A) ;
    do
    {
        sz = level.size () ;
        for (i = 0 ; i < sz - 1 ; i++)
        {
            tmp = level[i] ;
            tmp->next = level[i+1] ;
            if (tmp->left) level.push_back (tmp->left) ;
            if (tmp->right) level.push_back (tmp->right) ;
        }
        tmp = level[sz - 1] ;
        tmp->next = NULL ;
        if (tmp->left) level.push_back (tmp->left) ;
        if (tmp->right) level.push_back (tmp->right) ;
        
        level.erase (level.begin (), level.begin () + sz) ;
    } while (!level.empty ()) ;
}
