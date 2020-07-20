#define MOD 1000007

int Solution::coinchange2(vector<int> &A, int B) 
{
    int i, j, N = A.size() ;
    vector<long long> dp (B+1, 0) ;
    
    dp[0] = 1 ;
    for (j = 0 ; j < N ; j++)
    {
        for (i = A[j] ; i <= B ; i++)
            dp[i] = (dp[i] +  (dp[i - A[j]] % MOD)) % MOD ;
    }
    
    return dp[B] % MOD ;
}

