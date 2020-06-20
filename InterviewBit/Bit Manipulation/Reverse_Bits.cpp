unsigned int Solution::reverse(unsigned int A) {
    unsigned int ans = 0 ;
    int i, bit ;
    
    for (i = 0 ; i < 32 ; i++)
    {
        bit = A % 2 ;
        if (bit) 
            ans |= 1 << (32 - i) ;
        A = A >> 1 ;
    }
    
    return ans ;
}
