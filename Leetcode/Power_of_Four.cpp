class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if (!n || (n != 1 && n < 4))
            return false ;
        
        while (n != 1)
        {
            if (n % 4)
                return false ;
            n /= 4 ;
        }
        
        return true ;
        
    }
};
