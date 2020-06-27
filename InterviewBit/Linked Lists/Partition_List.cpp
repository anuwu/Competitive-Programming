ListNode* Solution::partition(ListNode* A, int B) 
{
    ListNode *lshead, *lstail, *grhead, *grtail, *tmp ;
    
    lshead = NULL ;
    grhead = NULL ;
    tmp = A ;
    while (tmp)
    {
        if (tmp->val < B)
        {
            if (lshead)
            {
                lstail->next = tmp ;
                lstail = tmp ;
            }
            else
            {
                lshead = tmp ;
                lstail = lshead ;
            }
        }
        else
        {
            if (grhead)
            {
                grtail->next = tmp ;
                grtail = tmp ;
            }
            else
            {
                grhead = tmp ;
                grtail = grhead ;
            }
        }
        
        tmp = tmp->next ;
    }
    
    if (!lshead)
        return grhead ;
    else
    {
        lstail->next = grhead ;
        if (grhead)
            grtail->next = NULL ;
    }
    
    return lshead ;
}
