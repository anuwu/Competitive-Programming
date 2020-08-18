typedef SinglyLinkedListNode slln ;

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) 
{
    if (!head)
        return NULL ;

    slln *tmp, *prev, *nex ;

    prev = NULL ;
    tmp = head ;
    while (tmp)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
    }
    
    return prev ;
}
