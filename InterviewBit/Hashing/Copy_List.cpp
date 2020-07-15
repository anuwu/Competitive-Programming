RandomListNode* Solution::copyRandomList(RandomListNode* A) 
{
    RandomListNode *tmp, *cophead, *cop, *prev ;
    unordered_map<RandomListNode*, RandomListNode*> m ;
    
    cophead = (RandomListNode*) malloc (sizeof (RandomListNode)) ;
    cophead->label = A->label ;
    m[A] = cophead ;
    

    prev = cophead ;
    tmp = A->next ;
    while (tmp)
    {
        cop = (RandomListNode*) malloc (sizeof (RandomListNode)) ;
        prev->next = cop ;
        cop->label = tmp->label ;
        m[tmp] = cop ;
        
        prev = cop ;
        tmp = tmp->next ;
    }
    prev->next = NULL ;
    
    tmp = A ;
    while (tmp)
    {
        m[tmp]->random = tmp->random ? m[tmp->random] : NULL ;
        tmp = tmp->next ;
    }
    
    
    return cophead ;
}
