struct cmpListNode
{
    bool operator()(const ListNode* lhs, const ListNode* rhs)
    {
        return lhs->val > rhs->val ;
    }
} ;
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) 
{
    int i ;
    ListNode *head, *tail, *min ;
    priority_queue<ListNode*, vector<ListNode*>, cmpListNode> pq ;  
    
    for (i = 0 ; i < A.size () ; i++)
        pq.push (A[i]) ;
    
    min = pq.top () ;
    head = min ;
    tail = head ;
    pq.pop () ;
    if (tail->next)
        pq.push (tail->next) ;
        
    while (!pq.empty ())
    {
        min = pq.top () ;
        tail->next = min ;
        tail = min ;
        pq.pop () ;
        
        if (tail->next)
            pq.push (tail->next) ;
    }
    
    tail->next = NULL ;
    return head ;
}
