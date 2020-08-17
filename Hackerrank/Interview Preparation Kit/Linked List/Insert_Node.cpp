SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) 
{
    if (!head)
    {
        head = (SinglyLinkedListNode*) malloc (sizeof (SinglyLinkedListNode)) ;
        head->data = data ;
        head->next = NULL ;
        return head ;
    }

    int i ;
    SinglyLinkedListNode *tmp, *ptr ;

    tmp = head ;
    i = 1 ;
    while (i < position)
    {
        tmp = tmp->next ;
        i++ ;
    }

    ptr = (SinglyLinkedListNode*) malloc (sizeof (SinglyLinkedListNode)) ;
    ptr->data = data ;
    ptr->next = tmp->next ;
    tmp->next = ptr ;

    return head ;

}
