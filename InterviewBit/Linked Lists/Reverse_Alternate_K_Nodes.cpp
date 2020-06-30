ListNode* Solution::solve(ListNode* A, int B) 
{
    bool rev ;
    int i = 0 ;
    ListNode *head, *btail, *bhead, *tmp, *prev, *nex ;
    
    i = 0 ;
    prev = NULL ;
    tmp = A ;
    while (i < B && tmp)
    {
        nex = tmp->next ;
        tmp->next = prev ;
        prev = tmp ;
        tmp = nex ;
        
        i++ ;
    }
    
    btail = A ;
    head = prev ;
    bhead = nex ;
    if (!bhead)
        return head ;
        
    rev = false ;
    do
    {
        if (rev)
        {
            i = 0 ;
            prev = NULL ;
            tmp = bhead ;
            while (i < B && tmp)
            {
                nex = tmp->next ;
                tmp->next = prev ;
                prev = tmp ;
                tmp = nex ;
                
                i++ ;
            }
            btail->next = prev ;
            btail = bhead ;
            bhead = nex ;
            
            rev = false ;
        }
        else
        {
            i = 0 ;
            btail->next = bhead ;
            tmp = bhead ;
            while (i < B - 1 && tmp)
            {
                tmp = tmp->next ;
                i++ ;
            }
                
            if (tmp)
            {
                btail = tmp ;
                bhead = tmp->next ;
            }
            else
                bhead = NULL ;
        
            rev = true ;
        }
    } while (bhead) ;
    
    return head ;
}
