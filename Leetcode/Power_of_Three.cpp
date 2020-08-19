class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if (!n || n == 2)
            return false ;
        
        while (n != 1)
        {
            if (n % 3)
                return false ;
            n /= 3 ;
        }
        
        return true ;
        
    }
};
