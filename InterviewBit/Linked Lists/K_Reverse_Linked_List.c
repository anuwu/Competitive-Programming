listnode* reverseList(listnode* A, int B) 
{
    if (B == 1)
        return A ;
    
    listnode *tmp, *prev, *nex, *rprev, *rhead, *ret ;
    int cnt = 1 ;
    
    printf ("Starting rev %d, ", A->val) ;
    rprev = NULL ;
    rhead = A ;
    while (rhead)
    {
        cnt = 1 ;
        prev = rprev ;
        tmp = rhead ;
        while (cnt != B)
        {
            nex = tmp->next ;
            tmp->next = prev ;
            prev = tmp ;
            tmp = nex ;
            
            cnt++ ;
        }
        
        printf ("Ending rev %d\n", tmp->val) ;
        nex = tmp->next ;
        tmp->next = prev ;
    
        if (rprev == NULL)
            ret = tmp ;
        else
            rprev->next = tmp ;
            
        rprev = rhead ;
        if (nex == NULL)
            rhead->next = NULL ;
        rhead = nex ;
        
        if (rhead)
            printf ("Starting rev %d, ", rhead->val) ;
        else
            printf ("No more rev\n") ;
    }
    
    return ret ;
}
