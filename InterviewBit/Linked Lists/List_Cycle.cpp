#include <bits/stdc++.h>
using namespace std ;
 
ListNode* Solution::detectCycle(ListNode* A) 
{
    unordered_set <ListNode*> lset ;
    int flag = 0 ;
    ListNode *tmp, *cycle = NULL ;
    
    tmp = A ;
    while (tmp->next)
    {
        lset.insert (tmp) ;
        
        tmp = tmp->next ;
        if (lset.find (tmp) != lset.end ())
        {
            cycle = tmp ;
            break ;
        }
    }
    
    return cycle ;
}
