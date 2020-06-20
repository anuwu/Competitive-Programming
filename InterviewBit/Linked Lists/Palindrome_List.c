int lPalin(listnode* A) 
{
    if (A->next == NULL)
        return 1 ;
    else if (A->next->next == NULL)
        return A->val == A->next->val ;
    else if (A->next->next->next == NULL)
        return A->val == A->next->next->val ;
        
    int i, len = 0 ;
    
    listnode *tmp, *stop, *lat, *prev, *nex ;
    
    tmp = A ;
    while (tmp)
    {
        len++ ;
        tmp = tmp->next ;
    }
    
    i = 0 ;
    stop = A ;
    while (i != len/2)
    {
        i++ ;
        stop = stop->next ;
    }
    
    if (len % 2)
        lat = stop->next ;
    else
        lat = stop ;
    
    prev = NULL ;
    tmp = A ;
    while (tmp->next != stop)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
    }
    tmp->next = prev ;
    
    while (tmp && lat)
    {
        if (tmp->val != lat->val)
            return 0 ;
            
        tmp = tmp->next ;
        lat = lat->next ;
    }
    
    return 1 ;
    
}
