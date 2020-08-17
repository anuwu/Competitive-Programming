#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007
#define UPAI 1000000
#define UPA 1000

vector<vector<long long>> comb ;
vector<long long> power ;
vector<bool> sieve ;

void fillSieve ()
{
    int p, sq ;
    
    p = 2 ;
    sq = 4 ;
    while (sq <= UPAI)
    {
        do
        {
            sieve[sq] = false ;
            sq += p ;
        } while (sq <= UPAI) ;
        
        do p++ ; while (p <= UPAI && !sieve[p]) ;
        sq = p*p ;
    }
}

void fillComb ()
{
    int n, r ;
    
    for (n = 1 ; n <= UPA ; n++)
        for (r = 1 ; r < n ; r++)
            comb[n][r] = (comb[n-1][r-1] + comb[n-1][r]) % (MOD - 1) ;
}

long long modMul (int x, long long y)
{
    if (y == 0)
        return 1 ;
    else if (y == 1)
        return x % MOD ;
    
    long long haf ;
    if (y % 2)
    {
        haf = modMul (x, y-1) ;
        return (x * haf) % MOD ;
    }
    else
    {
        haf = modMul (x, y/2) ;
        return (haf * haf) % MOD ;
    }
}

void fillPower ()
{
    int i ;
    
    for (i = 1 ; i <= UPA ; i++)
        power[i] = (power[i-1] * 2) % (MOD - 1) ;
}


void mscMath (vector<int> &A)
{
    int i, p, N = A.size() ;
    long long ans ;
    
    p = 0 ;
    for (i = 0 ; i < N ; i++)
        if (sieve[A[i]])
            p++ ;
    
    ans = 1 ;
    for (i = 0 ; i <= p ; i++)
        ans = (ans * modMul (i+2, (power[N-p] * comb[p][i]) % (MOD - 1))) % MOD ;

    cout << ans << "\n" ;
}



int main() 
{
    int i, t, N ;
    vector<int> A ;
    
    power.clear () ;
    power = vector<long long> (UPA + 1, 1) ;
    fillPower () ;
    
    comb.clear () ;
    comb = vector<vector<long long>> (UPA + 1, vector<long long> (UPA + 1, 1)) ;
    fillComb () ;
    
    sieve.clear () ;
    sieve = vector<bool> (UPAI + 1, true) ;
    fillSieve () ;
    
    cin >> t ;
    do
    {
        cin >> N ;
        A = vector<int> (N, 0) ;
        for (i = 0 ; i < N ; i++)
            cin >> A[i] ;
        
        mscMath (A) ;
        A.clear () ;
    } while (--t) ;
    
    return 0;
}
