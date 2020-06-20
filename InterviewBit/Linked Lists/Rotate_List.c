listnode* rotateRight(listnode* A, int B) 
{
    listnode *tmp, *prev, *ret ;
    int cnt = 0, len = 0 ;

    tmp = A ;
    while (tmp)
    {
        len++ ;
        tmp = tmp->next ;
    }
    
    B %= len ;
    if (B == 0)
        return A ;
        
    ret = A ;
    tmp = A ; prev = A ;
    cnt = 0 ;
    
    
    while (tmp->next)
    {
        ret = ret->next ;
        tmp = tmp->next ;
    }
    
    
    while (tmp)
    {
        cnt++ ;
        
        if (cnt == len - B)
        {
            prev->next = NULL ;
            ret = tmp ;
            while (tmp->next)
                tmp = tmp->next ;
                
            tmp->next = A ;
            return ret ;
        }
        
        prev = tmp ;
        tmp = tmp->next ;
    }
}
