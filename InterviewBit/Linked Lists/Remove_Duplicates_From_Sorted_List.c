listnode* deleteDuplicates(listnode* A) {
    listnode *curr, *prev, *nex ;
    int cv, nv ;
    
    curr = A ;
    cv = curr->val ;
    while (curr)
    {
        nex = curr->next ;
        while (nex && nex->val == cv)
            nex = nex->next ;
            
        curr->next = nex ;
        prev = curr ;
        curr = curr->next ;
    }
    
    
    curr = A ;
    while (curr)
    {
        printf ("%d, ", curr->val) ;
        curr = curr->next ;
    }
    
    printf ("Returning\n") ;
    return A ;
}
