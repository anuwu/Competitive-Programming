typedef SinglyLinkedListNode slln ;

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) 
{
    if (!head)
    {
        head = (SinglyLinkedListNode*) malloc (sizeof (SinglyLinkedListNode)) ;
        head->data = data ;
        head->next = NULL ;
        return head ;
    }

    slln *tmp, *node ;
    node = (slln*) malloc (sizeof (slln)) ;
    node->data = data ;
    node->next = NULL ;

    tmp = head ;
    while (tmp->next)
        tmp = tmp->next ;

    tmp->next = node ;
    return head ;
}
