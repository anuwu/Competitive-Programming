#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std ;

vector<long long> S ;

long long getCount (int N)
{
    if (N <= 2)
        return N ;
    
    int mpow, diff ;
    long long sum ;
    
    mpow = log(N)/log(2) ;
    sum = S[mpow - 1] + 1 ;
    diff = N - (1 << mpow) ;
    
    //printf ("%d %d %d %d\n", N, mpow, sum, diff) ;
    
    sum += (diff + getCount (diff)) ;
    return sum ;
}

void setbits (int N)
{
    if (N == 0 || N == 1)
    {
        cout << N << "\n" ;
        return ;
    }
    
    int i, mpow, pow2 ;
    long long sum ;
    
    mpow = log(N)/log(2) ;
    S.clear () ;
    S = vector<long long> (mpow+1, 1) ;
    

    pow2 = 2 ;
    for (i = 1 ; i <= mpow ; i++)
    {
        S[i] = 2*S[i-1] + pow2 ;
        pow2 *= 2 ;
    }
    
    sum = getCount (N) ;
    cout << sum << "\n" ;
}

int main() 
{
	int noTest, N, i ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N ;
	    setbits (N) ;
	}
	
	return 0;
}
