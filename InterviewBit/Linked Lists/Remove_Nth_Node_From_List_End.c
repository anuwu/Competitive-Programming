listnode* removeNthFromEnd(listnode* A, int B) {
    int len = 0 ;
    listnode *tmp, *rem, *prev ;
    
    rem = A ;
    tmp = A ;
    while (tmp->next)
    {
        len++ ;
        
        if (B == len)
            rem = A ;
        
        prev = rem ;
        tmp = tmp->next ;
        rem = rem->next ;
    }
    
    if (B >= len)
        return A->next ;
    
    printf ("Removed %d\n", rem->val) ;
    prev->next = rem->next ;
    return A ;
}
