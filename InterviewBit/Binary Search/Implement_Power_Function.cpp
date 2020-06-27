long long powhelp (long long x, long long n, long long d)
{
    if (n == 0)
    {
        if (x == 0)
            return 0 ;
        else
            return 1 ;
    }
    if (n == 1)
        return x % d ;

    if (n % 2 == 0)
    {
        long long res ;
        res = powhelp (x, n/2, d) ;
        return (res * res) % d ;
    }
    else
        return (powhelp (x, n - 1, d) * (x % d)) % d ;
}

int Solution::pow(int x, int n, int d) 
{
    if (n == 0)
    {
        if (x == 0)
            return 0 ;
        else
            return 1 ;
    }

    if (x < 0)
    {
        long long res ;
        res = powhelp (-x, n, d) ;
        
        if (n % 2 == 0)
            return res ;
        else
            return d - (res % d) ;
    }
    else
        return powhelp (x, n, d) ;
}
