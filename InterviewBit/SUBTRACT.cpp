ListNode* reverse (ListNode *head, ListNode *stop)
{
    ListNode *tmp, *prev, *nex ;
    
    prev = NULL ;
    tmp = head ;
    while (tmp->next != stop)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
    }
    tmp->next = prev ;
    
    return tmp ;
}
 
ListNode* Solution::subtract(ListNode* A) 
{
    if (A->next == NULL)
        return A ;
    if (A->next->next == NULL)
    {
        A->val = A->next->val - A->val ;
        return A ;
    }
    
    ListNode *tmp, *stop, *stopprev, *lat, *latrev, *revtmp ;
    
    tmp = A ;
    stop = A ;
    do
    {
        if (tmp->next == NULL)
        {
            stopprev = stop ;
            lat = stop->next ;
            break ;
        }
        else if (tmp->next->next == NULL)
        {
            stopprev = stop ;
            stop = stop->next ;
            lat = stop ;
            break ;
        }

        tmp = tmp->next->next ;
        stop = stop->next ;
    } while (true) ;
    
    latrev = reverse (lat, NULL) ;
   
    revtmp = latrev ;
    tmp = A ;
    while (tmp != stop)
    {
        tmp->val = revtmp->val - tmp->val ;
        
        revtmp = revtmp->next ;
        tmp = tmp->next ;
    }
    
    lat = reverse (latrev, NULL) ;
    stopprev->next = lat ;
    
    return A ;
}

