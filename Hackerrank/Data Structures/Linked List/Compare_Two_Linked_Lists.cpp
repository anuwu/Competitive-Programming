bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    if (!head1 && !head2)
        return true ;
    else if (head1 && head2)
        return head1->data == head2->data && compare_lists (head1->next, head2->next) ;
    else
        return false ;
}

