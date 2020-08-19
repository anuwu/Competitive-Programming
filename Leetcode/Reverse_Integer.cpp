class Solution {
public:
    int reverse(int x) 
    {
        int save, dig ;
        long long rev ;
        bool sgn ;
        
        sgn = false ;
        
        if (x == INT_MIN)
            return 0 ;
        
        if (x < 0)
        {
            sgn = true ;
            x = -x ;
        }
        
        save = x ;
        rev = 0 ;
        while (x)
        {
            dig = x % 10 ;
            rev = rev*10 + dig ;            
            x /= 10 ;
            
            if (rev > INT_MAX)
                return 0 ;
        }
        
        if (sgn)
            rev = -rev ;
        
        return rev ;
    }
};
