int Solution::solve(ListNode* A, int B) 
{
    int i, len, jmp ;
    ListNode *tmp ;
    
    len = 0 ;
    tmp = A ;
    while (tmp)
    {
        len++ ;
        tmp = tmp->next ;
    }
    
    jmp = len/2 ;
    jmp -= B ;
    
    if (jmp < 0)
        return -1 ;
    else
    {
        tmp = A ;
        i = 0 ;
        while (i < jmp && tmp)
        {
            tmp = tmp->next ;
            i++ ;
        }
        
        return tmp->val ;
    }
}

