int Solution::numSetBits(unsigned int A) {
    int ans = 0 ;
    
    for (int i = 0 ; i < 32 ; i++)
    {
        ans += A % 2 ;
        A = A >> 1 ;
    }
    
    return ans ;
}
