ListNode* Solution::solve(vector<vector<int>> &A) 
{
    int i, j, val, index, N, len ;
    ListNode *head, *tail, *tmp, *prev, *nex ;
    
    len = 0 ;
    head = NULL ;
    tail = NULL ;
    N = A.size() ;
    for (i = 0 ; i < N ; i++)
    {
        switch (A[i][0])
        {
            case 0 :
            {
                tmp = (ListNode *) malloc (sizeof (ListNode)) ;
                tmp->val = A[i][1] ;
                
                if (head)
                {
                    tmp->next = head ;
                    head = tmp ;
                }
                else
                {
                    head = tmp ;
                    tail = head ;
                    head->next = NULL ;
                }
                len++ ;
            }
            break ;
            
            case 1 :
            {
                tmp = (ListNode *) malloc (sizeof (ListNode)) ;
                tmp->val = A[i][1] ;
                tmp->next = NULL ;
                
                if (tail)
                {
                    tail->next = tmp ;
                    tail = tmp ;
                }
                else
                {
                    head = tmp ;
                    tail = head ;
                }
                len++ ;
            }
            break ;
            
            case 2 :
            {
                index = A[i][2] ;
                if (index > len || index < 0)
                    break ;
                else
                {
                    tmp = (ListNode *) malloc (sizeof (ListNode)) ;
                    tmp->val = A[i][1] ;
                    tmp->next = NULL ;
                    len++ ;
                    
                    if (index == len-1)
                    {
                        if (tail)
                        {
                            tail->next = tmp ;
                            tail = tmp ;
                        }
                        else
                        {
                            head = tmp ;
                            tail = head ;
                        }
                    }
                    else if (index == 0)
                    {
                        tmp->next = head ;
                        head = tmp ;
                        if (!tail)
                            tail = head ;
                    }
                    else
                    {
                        nex = head ;
                        prev = NULL ;
                        j = 0 ;
                        while (j < index)
                        {
                            prev = nex ;
                            nex = nex->next ; 
                            j++ ;
                        }
                        
                        prev->next = tmp ;
                        tmp->next = nex ;
                    }
                }
            }
            break ;
            
            case 3 :
            {
                index = A[i][1] ;
                
                if (index >= len || index < 0)
                    break ;
                else if (index == 0)
                {
                    if (tail == head)
                        tail = NULL ;
                    head = head->next ;
                }
                else
                {
                    tmp = head ;
                    prev = NULL ;
                    j = 0 ;
                    while (j < index)
                    {
                        prev = tmp ;
                        tmp = tmp->next ;
                        j++ ;
                    }
                    
                    if (tmp == tail)
                        tail = prev ;
                    prev->next = tmp->next ;
                }
                
                len-- ;
            }   
            break ;
            
        }
    }
    
    return head ;
}

