ution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    ListNode *tmp1, *tmp2, *curr, *head ;
    
    tmp1 = A ;
    tmp2 = B ;
    if (A->val < B->val)
    {
        head = A ;
        tmp1 = tmp1->next ;
    }
    else
    {
        head = B;
        tmp2 = tmp2->next ;
    }
    
    curr = head ;
    while (tmp1 && tmp2)
    {
        if (tmp1->val < tmp2->val)
        {
            curr->next = tmp1 ;
            curr = tmp1 ;
            tmp1 = tmp1->next ;
        }
        else
        {
            curr->next = tmp2 ;
            curr = tmp2 ;
            tmp2 = tmp2->next ;
        }
    }
    
    if (tmp1)
        curr->next = tmp1 ;
    if (tmp2)
        curr->next = tmp2 ;
        
    return head ;
}

