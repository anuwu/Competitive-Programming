ListNode* Solution::reverseList(ListNode* A) 
{
    if (A->next == NULL)
        return A ;
        
    ListNode *nex, *head ;
    nex = A->next ;
    A->next = NULL ;
    head = reverseList (nex) ;
    nex->next = A ;
    
    return head ;
}

