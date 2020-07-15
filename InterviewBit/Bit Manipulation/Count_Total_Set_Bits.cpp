#define MOD 1000000007

vector<long long> S ;

long long getCount (int N)
{
    if (N <= 2)
        return N ;
    
    int mpow, diff ;
    long long sum ;
    
    mpow = log(N)/log(2) ;
    sum = (S[mpow - 1] + 1) % MOD ;
    diff = N - (1 << mpow) ;
    
    sum = (sum + ((diff + getCount (diff)) % MOD)) % MOD ;
    return sum ;
}

int Solution::solve (int N)
{
    if (N == 0 || N == 1)
        return N ;
    
    int i, mpow, pow2 ;
    long long sum ;
    
    mpow = log(N)/log(2) ;
    S.clear () ;
    S = vector<long long> (mpow + 1, 1) ;
    
    pow2 = 2 ;
    for (i = 1 ; i <= mpow ; i++)
    {
        S[i] = (((2*S[i-1]) % MOD) + (pow2 % MOD)) % MOD ;
        pow2 *= 2 ;
    }
    
    sum = getCount (N) ;
    return sum ;
}
