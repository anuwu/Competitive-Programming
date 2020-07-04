#define MOD 1000000007
 
int Solution::hammingDistance(const vector<int> &A) 
{
    int bit, i, N ;
    long long cnt, sum ;
    
    sum = 0 ;
    N = A.size () ;
    for (bit = 0 ; bit < 32 ; bit++)
    {
        cnt = 0 ;
        for (i = 0 ; i < N ; i++)
            if ((A[i] & (1 << bit)))
                cnt = (cnt + 1) % MOD ;
            
        cnt = (cnt * (N - cnt)) % MOD ;
        cnt = (cnt * 2) % MOD ;
        sum = (sum + (cnt % MOD)) % MOD ;
    }
    
   
    return (int)sum ;
}
