class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        int last, lim ;
        
        for (lim = 31 ; lim >= 0 ; lim--)
            if (n >> lim & 1)
                break ;
        
        last = n & 1 ;
        for (int i = 1 ; i <= lim ; i++)
            if (!(last ^ (n >> i & 1)) & ((last = n >> i & 1) | true))
                return false ;
        
        return true ;
    }
};
