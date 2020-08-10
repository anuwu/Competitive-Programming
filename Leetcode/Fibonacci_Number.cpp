class Solution {
public:
    int fib(int N) 
    {
        if (N == 0)
            return 0 ;
        else if (N == 1)
            return 1 ;
        
        int i ;
        vector<int> fib (N+1, 0) ;
        
        fib[0] = 0 ;
        fib[1] = 1 ;
        for (i = 2 ; i <= N ; i++)
            fib[i] = fib[i-1] + fib[i-2] ;
        
        return fib[N] ;        
    }
};
