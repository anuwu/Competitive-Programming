class Solution {
public:
    int tribonacci(int n) 
    {
        if (n == 0)
            return 0 ;
        else if (n == 1)
            return 1 ;
        else if (n == 2)
            return 1 ;
        
        int i ;
        vector<int> trib (n+1, 0) ;
        trib[0] = 0 ;
        trib[1] = 1 ;
        trib[2] = 1 ;
        for (i = 3 ; i <= n ; i++)
            trib[i] = trib[i-1] + trib[i-2] + trib[i-3] ;
        
        return trib[n] ;
        
    }
};
