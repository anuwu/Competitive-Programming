Node *copyList(Node *head) 
{
    Node *cophead, *prev, *cop, *tmp, *nex, *arbptr ;
    unordered_map<Node*,Node*> ptrMap ;
    
    cophead = (Node*) malloc (sizeof (Node)) ;
    cophead->data = head->data ;
    
    nex = head->next ;
    head->next = cophead ;
    cophead->arb = head ;
    ptrMap[cophead] = head ;
    
    prev = cophead ;
    do
    {
        tmp = nex ;
        
        cop = (Node*) malloc (sizeof (Node)) ;
        cop->data = tmp->data ;
        prev->next = cop ;
        
        nex = tmp->next ;
        tmp->next = cop ;
        cop->arb = tmp ;
        ptrMap[cop] = tmp ;

        prev = cop ;
    } while (nex) ;
    prev->next = NULL ;
    
    cop = cophead ;
    while (cop)
    {
        arbptr = cop->arb->arb ;
        if (arbptr)
            cop->arb = arbptr->next ;
        else
            cop->arb = NULL ;
            
        cop = cop->next ;
    }
    
    tmp = cophead ;
    while (tmp)
    {
        ptrMap[tmp]->next = ptrMap[tmp->next] ;
        tmp = tmp->next ;
    }
    
    
    return cophead ;
}
