listnode *revList (listnode* node)
{
    listnode *tmp, *prev, *nex ;
    
    prev = NULL ;
    tmp = node ;
    while (tmp->next)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
    }
    
    tmp->next = prev ;
    return tmp ;
}

int getLen (listnode* node)
{
    listnode* tmp ;
    int len = 0 ;
    
    tmp = node ;
    while (tmp)
    {
        len++ ;
        tmp = tmp->next ;
    }
    
    return len ;
}

listnode* getIntersectionNode(listnode* A, listnode* B) 
{
    if (A == NULL || B == NULL)
        return NULL ;
    
    listnode *tmp, *revA, *inter ;
    int lenA, lenB, lenACB, flag  ;
    
    lenA = getLen (A) ;
    lenB = getLen (B) ;

    revA = revList (A) ;
    tmp = B ;
    lenACB = 0 ;
    flag = 1 ;
    while (tmp)
    {
        lenACB++ ;
        if (tmp == A)
            flag = 0 ;
            
        tmp = tmp->next ;
    }
    if (flag)
        return NULL ;
        
    int a, cnt ;
    a = ((lenACB - 1) + lenA - lenB) / 2 ;
    
    A = revList (revA) ;
    tmp = A ;
    cnt = 0 ;
    while (cnt != a)
    {
        tmp = tmp->next ;
        cnt++ ;
    }
    
    return tmp ;
}
