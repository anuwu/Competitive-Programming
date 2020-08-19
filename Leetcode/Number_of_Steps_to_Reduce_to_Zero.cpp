class Solution {
public:
    int numberOfSteps (int n) 
    {
        if (n == 0)
            return 0 ;
        
        int steps = 0 ;
        
        while (n != 0)
        {
            if (n % 2)
                n-- ;
            else
                n /= 2 ;
            
            steps++ ;
        }
        
        return steps ;
        
    }
};
