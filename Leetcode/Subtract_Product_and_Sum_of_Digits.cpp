class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        long long prod, sum ;   
        int dig ;
        
        prod = 1 ;
        sum = 0 ;
        while (n)
        {
            dig = n % 10;
            prod *= dig ;
            sum += dig ;
            n /= 10 ;
        }
        
        return prod - sum ;
    }
};
