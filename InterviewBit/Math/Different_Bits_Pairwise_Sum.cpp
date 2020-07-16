#define MOD 1000000007

int Solution::cntBits(vector<int> &A) 
{
    long long bit, i, onecnt, N = A.size() ;
    long long sum ;
    
    sum = 0 ;
    for (bit = 0 ; bit < 31 ; bit++)
    {
        onecnt = 0 ;
        for (i = 0 ; i < N ; i++)
            if (A[i] & (1 << bit))
                onecnt++ ;
                
        sum = (sum + ((onecnt * (N - onecnt)) % MOD)) % MOD ;
    }
    
    return (2*sum) % MOD ;
}

