int Solution::divide(int A, int B) 
{
    if (A == INT_MIN)
    {
        if (B == -1)
            return INT_MAX ;
        else if (B == 1)
            return INT_MIN ;
    }
    
    if (B == 0)
        return INT_MAX ;
        
    long long a, b, dvdnd, dvsor, quotient, quo ;
    bool sign ;
    
    a = A ;
    b = B ;
    a = abs(a) ;
    b = abs(b) ;

    sign = (A < 0) ^ (B < 0) ;
    
    if (b == 1)
        return sign ? -a : a ;
    if (b > a)
        return 0 ;
        
    quotient = 0 ;
    dvdnd = a ;
    do
    {
        dvsor = b ;
        quo = 1 ;
        while ((dvsor << 1) <= dvdnd)
        {
            dvsor <<= 1 ;
            quo <<= 1 ;
        }
        
        quotient += quo ;
        dvdnd -= dvsor ;
    } while (dvdnd >= b) ;
    
    return sign ? -quotient : quotient ;
}
