
ListNode* Solution::solve(ListNode* A)
{
    if (A->next == NULL)
        return NULL ;
        
    ListNode *end, *mid, *prev ;
    
    end = mid = A ;
    while (true)
    {
        if (end->next && end->next->next == NULL)
        {
            prev = mid ;
            mid = mid->next ;
            break ;
        }
        else if (end->next == NULL)
            break ;
        
        end = end->next->next ;
        prev = mid ;
        mid = mid->next ;
    }
    
    prev->next = mid->next ;
    return A ;
}

