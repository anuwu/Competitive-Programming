int Solution::solve(ListNode* A) 
{
    int len, cnt, mid ;
    ListNode *tmp ;
    
    len = 0 ;
    tmp = A ;
    while (tmp)
    {
        len++ ;
        tmp = tmp->next ;
    }
    
    mid = len/2 + 1 ;
    cnt = 1 ;
    tmp = A ;
    while (cnt != mid)
    {
        cnt++ ;
        tmp = tmp->next ;
    }
    
    return tmp->val ;
}
