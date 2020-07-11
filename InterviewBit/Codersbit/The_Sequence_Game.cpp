#define MOD 1000000007

long long power (int n, int k)
{
    if (k == 1)
        return n ;
    
    if (k % 2 == 0)
    {
        long long p ;
        p = power (n, k/2) ;
        return (p * p) % MOD ;
    }
    else
        return (n * power (n, k-1)) % MOD ;
}

int Solution::solve(int n, int k) 
{
    if (n == 1)
        return 1 ;
    else if (k == 1)
        return n ;
        
    return power (n, k) ;
}

