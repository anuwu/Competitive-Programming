bool has_cycle(Node* head) 
{
    if (!head)
        return false ;
    
    Node *prev, *tmp, *nex ;
    
    prev = NULL ;
    tmp = head ;
    nex = tmp->next ;
    tmp->next = prev ;
    prev = tmp ;
    tmp = nex ;
    
    while (tmp)
    {
        if (tmp == head)
            return true ;
        
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
    }
    
    return false ;
}
