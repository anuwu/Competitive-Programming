listnode* deleteDuplicates(listnode* A) 
{
    listnode *head, *tmp, *prev, *nex ;
    int cv, nv ;
    
    head = A ;
    tmp = A ; prev = A ;
    while (tmp)
    {
        nex = tmp->next ;
        if (nex && nex->val == tmp->val)
        {
            while (nex && nex->val == tmp->val)
                nex = nex->next ;
                
            if (tmp == head)
                head = nex ;
            else
                prev->next = nex ;
                
            tmp = nex ;
            if (tmp == NULL)
                return head ;
        }
        
        prev = tmp ;
        tmp = tmp->next ;
    }
    
    return head ;
}
