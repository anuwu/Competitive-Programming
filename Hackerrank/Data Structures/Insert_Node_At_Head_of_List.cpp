SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) 
{
    SinglyLinkedListNode *head ;

    head = (SinglyLinkedListNode*) malloc (sizeof(SinglyLinkedListNode)) ;
    head->data = data ;
    head->next = llist ;

    return head ;
}

