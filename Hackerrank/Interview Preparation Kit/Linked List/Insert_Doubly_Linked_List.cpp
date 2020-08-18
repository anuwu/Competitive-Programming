DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) 
{
    if (!head)
    {
        head = (DoublyLinkedListNode*) malloc (sizeof (DoublyLinkedListNode)) ;
        head->data = data ;
        head->next = NULL ;
        head->prev = NULL ;


        return head ;
    }

    DoublyLinkedListNode *tmp, *prev, *node ;

    prev = NULL ;
    tmp = head ;
    while (tmp && tmp->data <= data)
    {
        prev = tmp ;
        tmp = tmp->next ;
    }

    node = (DoublyLinkedListNode*) malloc (sizeof (DoublyLinkedListNode)) ;
    node->data = data ;
    if (!prev)
    {
        node->next = head ;
        head->prev = node ;
        node->prev = NULL ;

        return node ;
    }
    else
    {
        prev->next = node ;
        node->prev = prev ;
        node->next = tmp ;
        if (tmp)
            tmp->prev = node ;
    }

    return head ;
}

