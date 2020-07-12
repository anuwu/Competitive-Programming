#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void lpf (int N)
{
    int i, p, sq ;
    vector<bool> sieve (N+1, false) ;
    vector<int> lpfArr (N+1, 1) ;
    
    p = 2 ;
    lpfArr[p] = p ;
    sq = p*p ;
    while (sq <= N)
    {
        while (sq <= N)
        {
            if (!sieve[sq])
            {
                sieve[sq] = true ;
                lpfArr[sq] = p ;
            }
            sq += p ;
        }
        
        do p++ ; while (sieve[p]) ;
        lpfArr[p] = p ;
        sq = p*p ;
    }
    
    for ( ; p <= N ; p++)
        if (!sieve[p])
            lpfArr[p] = p ;
    
    for (i = 1 ; i <= N ; i++)
        cout << lpfArr[i] << " " ;
    
    
    cout << "\n" ;
}

int main() 
{
    int noTest, i, N ;
    
    cin >> noTest ;
    for (i = 0 ; i < noTest ; i++)
    {
        cin >> N ;
        lpf (N) ;
    }
	
	return 0;
}
