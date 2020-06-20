ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
    ListNode *sumnode, *zero, *zeroprev, *other, *sumprev, *head ;
    int sum, carry, trail = 0 ;
    
    zero = zeroprev = sumprev = NULL ;
    carry = 0 ;
    sumnode = A ; head = A ;
    other = B ;
    while (sumnode && other)
    {
        sum = sumnode->val + other->val + carry ;
        carry = sum/10 ;
        sum %= 10 ;
        sumnode->val = sum ;
        
        if (!sum) 
        {
            if (!trail) zeroprev = sumprev ;
            trail = 1 ;
            zero = sumnode ;
        }
        else
            trail = 0 ;
        
        sumprev = sumnode ;
        sumnode = sumnode->next ;
        other = other->next ;
    }
    
    if (!sumnode && other)
    {
        sumnode = other ;
        sumprev->next = sumnode ;
    }
        
    while (sumnode)
    {
        sum = sumnode->val + carry ;
        carry = sum/10 ;
        sum %= 10 ;
        sumnode->val = sum ;
        
        if (!sum) 
        {
            if (!trail) zeroprev = sumprev ;
            trail = 1 ;
            zero = sumnode ;
        }
        else
            trail = 0 ;
        
        sumprev = sumnode ;
        sumnode = sumnode->next ;
    }
    
    if (carry)
    {
        sumprev->next = (ListNode*) malloc (sizeof(ListNode)) ;
        sumprev->next->val = 1 ;
        sumprev->next->next = NULL ;
        trail = 0 ;
    }
    
    if (trail)
        zeroprev->next = NULL ;
    
    return head ;
}
