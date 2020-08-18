void printLinkedList(SinglyLinkedListNode* head)
{
    while (head)
    {
        printf ("%d\n", head->data) ;
        head = head->next ;
    }
}
