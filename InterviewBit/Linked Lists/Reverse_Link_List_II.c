listnode* reverseBetween(listnode* A, int B, int C) 
{
    if (B == C)
        return A ;
        
    listnode *tmp, *prev, *nex, *prehead ;
    int cnt = 1 ;
    
    tmp = A ; prev = NULL ;
    while (cnt != B)
    {
        prev = tmp ;
        tmp = tmp->next ;
        cnt++ ;
    }
    prehead = prev ;
    

    if (B == 1)
        prev = NULL ;
    else
        prev = tmp ;
    while (cnt != C)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
        
        cnt++ ;
    }

    if (prehead == NULL)
        A->next = tmp->next ;
    else
    {
        prehead->next->next = tmp->next ;
        prehead->next = tmp ;
    }
    tmp->next = prev ;
    
    return A ;
}
