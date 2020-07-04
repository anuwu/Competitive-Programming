pair<ListNode*,ListNode*> cutList (ListNode *head)
{
    if (!head)
        return make_pair ((ListNode*)NULL, (ListNode*)NULL) ;
    if (head->next == NULL)
        return make_pair (head, (ListNode*)NULL) ;
    if (head->next->next == NULL)
    {
        ListNode *tmp ;
        tmp = head->next ;
        head->next = NULL ;
        return make_pair (head, tmp) ;
    }
    
    ListNode *tmp, *mid, *midprev ;
    
    tmp = head ;
    mid = head ;
    do
    {
        if (tmp->next == NULL || tmp->next->next == NULL)
        {
            midprev = mid ;
            mid = mid->next ;
            midprev->next = NULL ;
            
            return make_pair (head, mid) ;
        }
 
        tmp = tmp->next->next ;
        midprev = mid ;
        mid = mid->next ;
    } while (true) ;
}
 
ListNode* mergeList (ListNode *A, ListNode *B)
{
    if (A == NULL)
        return B ;
    if (B == NULL)
        return A ;
        
    ListNode *head, *tail, *tmp1, *tmp2 ;
    tmp1 = A ;
    tmp2 = B ;
    if (A->val < B->val)
    {
        head = A ;
        tmp1 = tmp1->next ;
    }
    else
    {
        head = B ;
        tmp2 = tmp2->next ;
    }
    
    tail = head ;
    while (tmp1 && tmp2)
    {
        if (tmp1->val < tmp2->val)
        {
            tail->next = tmp1 ;
            tail = tmp1 ;
            tmp1 = tmp1->next ;
        }
        else
        {
            tail->next = tmp2 ;
            tail = tmp2 ;
            tmp2 = tmp2->next ;
        }
    }
    
    if (tmp1)
        tail->next = tmp1 ;
    if (tmp2)
        tail->next = tmp2 ;
        
    return head ;
}
   
ListNode* Solution::sortList(ListNode*  A) 
{
    if (!A)
        return NULL ;
    if (A->next == NULL)
        return A ;
        
    ListNode *tmp1, *tmp2 ;
    pair<ListNode*,ListNode*> cutter ;
    
    cutter = cutList (A) ;
    tmp1 = sortList (cutter.first) ;
    tmp2 = sortList (cutter.second) ;
    
    return mergeList (tmp1, tmp2) ;
}
