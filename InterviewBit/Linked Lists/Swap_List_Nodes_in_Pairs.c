listnode* swapPairs(listnode* A) {
    if (A->next == NULL)
        return A ;
        
    listnode *tmp1, *tmp2, *nex, *prev, *head ;
    
    prev = NULL ;
    tmp1 = A ;
    tmp2 = A->next ; head = tmp2 ;
    while (tmp1 && tmp2)
    {
        nex = tmp2->next ;
        tmp1->next = nex ;
        tmp2->next = tmp1 ;
        
        if (prev)
            prev->next = tmp2 ;
          
        prev = tmp1 ;   
        tmp1 = nex ;
        if (nex)
            tmp2 = nex->next ;
    }
    
    return head ;
}
