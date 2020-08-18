
typedef SinglyLinkedListNode slln ;

bool has_cycle(SinglyLinkedListNode* head) 
{
    if (!head)
        return false ;

    slln *tmp, *prev, *nex ;

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
