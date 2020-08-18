DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) 
{
    if (!head || head->next == NULL)
        return head ;


    DoublyLinkedListNode *prev, *tmp, *nex ;

    prev = NULL ;
    tmp = head ;
    while (tmp)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        tmp->prev = nex ;
        prev = tmp ;
        tmp = nex ;
    }

    return prev ;
}
