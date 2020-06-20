listnode* reverseList(listnode* A)
{
    if (tmp == NULL || tmp->next == NULL)
        return tmp ;
    
    listnode *prev, *tmp, *nex ;
    
    prev = NULL ;
    tmp = A ;
    while (tmp->next)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
    }
    
    return tmp ;
}
