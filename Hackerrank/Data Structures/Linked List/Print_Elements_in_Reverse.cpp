void reversePrint(SinglyLinkedListNode* head) 
{
    if (!head)
        return ;

    reversePrint (head->next) ;
    cout << head->data << "\n" ;
}
