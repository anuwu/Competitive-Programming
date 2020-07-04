ListNode* getTail (ListNode *head, int val)
{
    int notval = val ? 0 : 1 ;
    
    while (head->next)
    {
        if (head->next->val == notval)
            break ;
        head = head->next ;
    }
    
    return head ;
}

ListNode* Solution::solve(ListNode* A) 
{
    if (A->next == NULL)
        return A ;
     
    ListNode *head, *zhead, *ztail, *ohead, *otail, *zprev, *oprev, *tmp ;
    
    if (A->val == 0)
    {
        head = A ;
        zhead = A ;
        ztail = getTail (zhead, 0) ;
        
        ohead = ztail->next ;
        if (!ohead)                 // List contains only zeros
            return A ;
            
        otail = getTail (ohead, 1) ;
    }
    else
    {
        ohead = A ;
        otail = getTail (ohead, 1) ;
        
        zhead = otail->next ;       // List contains only ones
        if (!zhead)
            return A ;
        head = zhead ;
        ztail = getTail (zhead, 0) ;
    }
    
    if (ztail->next == ohead)
        tmp = otail->next ;
    else
        tmp = ztail->next ;
        
    while (tmp)
    {
        if (tmp->val)
        {
            otail->next = tmp ;
            otail = tmp ;
        }
        else
        {
            ztail->next = tmp;
            ztail = tmp ;
        }
        tmp = tmp->next ;
    }
    
    ztail->next = ohead ;
    otail->next = NULL ;
    
    return head ;
}

