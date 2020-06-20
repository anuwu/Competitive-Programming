int a, b ;

int getgcd (int max, int min)
{
    if (min == 0) return max ;
    
    a = max - min ;
    b = min ;
    max = (a > b) ? a : b ;
    min = (a < b) ? a : b ;
    
    return getgcd (max, min) ;
}

int Solution::gcd(int A, int B) 
{
    if (!A) return B ;
    if (!B) return A ;
    if (A == 1 || B == 1) return 1 ;

    int max, min ;
    max = (A > B) ? A : B ;
    min = (A < B) ? A : B ;
    
    return getgcd (max, min) ;
}
