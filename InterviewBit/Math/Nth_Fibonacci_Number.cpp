#define MOD 1000000007

vector<vector<long long>> mul (vector<vector<long long>> M1, vector<vector<long long>> M2)
{
    int i, j, k ;
    vector<vector<long long>> ans (2, vector<long long> (2, 0)) ;
    
    for (i = 0 ; i < 2 ; i++)
    {
        for (j = 0 ; j < 2 ; j++)
        {
            ans[i][j] = 0 ;
            for (k = 0 ; k < 2 ; k++)
                ans[i][j] = (ans[i][j] % MOD +  (((M1[i][k] % MOD) * (M2[k][j] % MOD)) % MOD)) % MOD ;
        }
    }
    
    return ans ;
}

vector<vector<long long>> matPow (vector<vector<long long>> M, int p)
{
    if (p == 1)
        return M ;
    
    if (p % 2)
        return mul (matPow(M, p-1), M) ;
    else
    {
        vector<vector<long long>> M2 ;
        M2 = matPow (M, p/2) ;
        return mul (M2, M2) ;
    }
}

int fib (int n)
{
    int f1, f2 ;
    vector<vector<long long>> mat (2, vector<long long> (2, 0)) ;
    
    mat[0][0] = 1 ;
    mat[0][1] = 1 ;
    mat[1][0] = 1 ;
    mat[1][1] = 0 ;
    mat = matPow (mat, n - 2) ;
    
    return (mat[0][0] + mat[0][1]) % MOD ;
}

int Solution::solve(int A) 
{
    if (A == 1 || A == 2)
        return 1 ;
    
    return fib (A) ;
}
