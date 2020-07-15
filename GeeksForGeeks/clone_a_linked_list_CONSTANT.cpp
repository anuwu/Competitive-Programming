Node *copyList(Node *head) 
{
    Node *tmp, *nex, *cop, *cophead, *prevtmp, *prevcop, *nextmp, *nexcop ;
    
    nex = head ;
    do
    {
        tmp = nex ;
        cop = (Node*) malloc (sizeof (Node)) ;
        cop->data = tmp->data ;
        
        nex = tmp->next ;
        tmp->next = cop ;
        cop->next = nex ;
    } while (nex) ;
    
    tmp = head ;
    while (tmp)
    {
        tmp->next->arb = tmp->arb ? tmp->arb->next : NULL ;
        tmp = tmp->next->next ;
    }
    

    cophead = head->next ;
    
    prevtmp = head ;
    prevcop = cophead ;
    nextmp = prevcop->next ;
    nexcop = nextmp->next ;
    do
    {
        tmp = nextmp ;
        cop = nexcop ;
        
        prevtmp->next = tmp ;
        prevcop->next = cop ;
        
        prevtmp = tmp ;
        prevcop = cop ;
        nextmp = prevcop->next ;
        nexcop = nextmp ? nextmp->next : NULL ;
    } while (nextmp) ;
    prevtmp->next = NULL ;
    prevcop->next = NULL ;
    
    
    return cophead ;
}
