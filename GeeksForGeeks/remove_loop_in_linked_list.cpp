void removeLoop(Node* head)
{
    int slowLength, circLength, all ;
    Node *slow, *fast, *ptr, *nex, *tmp, *prev ;
    
    slowLength = 1 ;
    slow = head ;
    fast = head->next ;
    while (slow && fast)
    {
        if (slow == fast || fast->next == slow)
            break ;
        
        slow = slow->next ;
        slowLength++ ;
        if (fast->next)
            fast = fast->next->next ;
        else
            return ;
    }
    
    if (!fast)
        return ;
    
    circLength = 1 ;
    ptr = slow->next ;
    while (ptr != slow)
    {
        ptr = ptr->next ;
        circLength++ ;
    }
    
    if (circLength == 1)
    {
        ptr->next = NULL ;
        return ;
    }
    
    all = -1 ;
    tmp = head ;
    prev = NULL ;
    while (tmp)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
        
        all++ ;
    }
    
    //printf ("%d %d %d\n", slowLength, circLength, all) ;
    
    int acplus, acminus, toTail ;
    acplus = all - slowLength ;
    acminus = slowLength - circLength ;
    toTail = (acplus - acminus)/2 ;
    
    tmp = head ;
    prev = NULL ;
    while (tmp)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
    }
    
    int i ;
    tmp = ptr ;
    for (i = 0 ; i < toTail ; i++)
        tmp = tmp->next ;
    
    tmp->next = NULL ;
}
