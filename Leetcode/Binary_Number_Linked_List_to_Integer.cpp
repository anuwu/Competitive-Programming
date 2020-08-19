
class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        if (!head)
            return 0 ;
        
        int ans, n ;
        vector<int> a ;
        ListNode *tmp ;
        
        tmp = head ;
        while (tmp)
        {
            a.push_back (tmp->val) ;
            tmp = tmp->next ;
        }
        
        ans = 0 ;
        n = a.size() ;
        for (int i = 0 ; i < n ; i++)
            ans += a[i] * (int)pow (2, n-i-1) ;
        
        return ans ;
        
    }
};
