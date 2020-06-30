ListNode* Solution::insertionSortList(ListNode* A) 
{
    ListNode *head, *tail, *tmp, *nex, *ptr, *prev ;
    
    head = A ;
    tail = A ;
    while (tail->next)
    {
        tmp = tail->next ;
        
        if (tmp->val >= tail->val)
            tail = tmp ;
        else
        {
            nex = tmp->next ;
            tail->next = nex ;
            
            if (tmp->val < head->val)
            {
                tmp->next = head ;
                head = tmp ;
            }
            else
            {
                ptr = head ;   
                prev = NULL ;
                while (tmp->val >= ptr->val)
                {
                    prev = ptr ;
                    ptr = ptr->next ;
                }
                
                prev->next = tmp ;
                tmp->next = ptr ;
            }
        }
    }
    
    return head ;
}

