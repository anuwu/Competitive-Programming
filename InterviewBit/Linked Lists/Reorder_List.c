listnode* reorderList(listnode* A) 
{
    if (A->next == NULL || A->next->next == NULL)
        return A ;
    else if (A->next->next->next == NULL)
    {
        listnode *tmp ;
        tmp = A->next ;
        A->next = tmp->next ;
        A->next->next = tmp ;
        tmp->next = NULL ;
        
        return A ;
    }
    
    
    
    listnode *tmp, *mid, *lat, *prev, *nex1, *nex2 ;
    int i, len = 0 ;
    
    tmp = A ;
    while (tmp)
    {
        len++ ;
        tmp = tmp->next ;
    }
    
    i = 0 ;
    mid = A ;
    while (i != len/2)
    {
        i++ ;
        mid = mid->next ;
    }
    
    if (len % 2 == 0)
    {
        lat = mid ;
        mid = NULL ;
        prev = NULL ;
    }
    else
    {
        lat = mid->next ;
        mid->next = NULL ;
        prev = mid ;
    }

    while (lat->next)
    {
        nex1 = lat->next ;
        lat->next = prev ;
        prev = lat ;
        lat = nex1 ;
    }
    lat->next = prev ;
    
    tmp = A ;
    while (lat)
    {
        nex1 = tmp->next ;
        nex2 = lat->next ;
        
        tmp->next = lat ;
        lat->next = nex1 ;
        
        tmp = nex1 ;
        lat = nex2 ;
    }
    
    if (tmp)
        tmp->next = NULL ;
        
    tmp = A ;
    while (tmp)
        tmp = tmp->next ;
    
    return A ;
}