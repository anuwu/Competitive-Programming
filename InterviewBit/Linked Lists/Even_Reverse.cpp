ListNode* Solution::solve(ListNode* A) 
{
    if (A == NULL || A->next == NULL || A->next->next == NULL || A->next->next->next == NULL)
        return A ;
        
    ListNode *oddhead, *oddtail, *evnex, *evhead, *evtail, *prev, *tmp1, *nex1 ;
    
    oddhead = A ;
    evhead = A->next ;
    oddtail = oddhead ;
    evtail = evhead ;
    do
    {
        evnex = evtail->next ;
        if (evnex)
            evnex = evnex->next ;
            
        oddtail->next = evtail->next ;
        oddtail = oddtail->next ;
        evtail->next = evnex ;
        evtail = evnex ;
        
        if (evtail->next == NULL)
        {
            oddtail->next = NULL ;
            break ;
        }
        else if (evtail->next->next == NULL)
        {
            oddtail->next = evtail->next ;
            evtail->next = NULL ;
            oddtail = oddtail->next ;
            
            break ;
        }
    } while (true) ;
    
    prev = NULL ;
    tmp1 = evhead ;
    while (tmp1->next)
    {
        nex1 = tmp1->next ;
        tmp1->next = prev ;
        prev = tmp1 ;
        tmp1 = nex1 ;
    }
    tmp1->next = prev ;
    evhead = tmp1 ;
    
    ListNode *tmp2, *nex2 ;
    tmp1 = oddhead ;
    tmp2 = evhead ;
    
    while (tmp1 && tmp2)
    {
        nex1 = tmp1->next ;
        nex2 = tmp2->next ;
        tmp1->next = tmp2 ;
        tmp2->next = nex1 ;
        
        tmp1 = nex1 ;
        tmp2 = nex2 ;
    }
    
    
    return oddhead ;
}
