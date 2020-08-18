typedef SinglyLinkedListNode slln ;

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) 
{
    if (position == 0)
    {
        if (head)
            head = head->next ;

        return head ;
    }

    int i ;
    slln *tmp ;

    tmp = head ;
    i = 1 ;
    while (tmp && i < position)
    {
        tmp = tmp->next ;
        i++ ;
    }

    tmp->next = tmp->next ? tmp->next->next : NULL ;
    return head ;
}
