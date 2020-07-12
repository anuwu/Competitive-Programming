#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void uniquebst (int N)
{
    if (N == 0 || N == 1)
    {
        cout << 1 << "\n" ;
        return ;
    }
    
    int i, j ;
    vector<long long> catalan (N+1, 0) ;
    
    catalan[0] = 1 ;
    catalan[1] = 1 ;
    for (i = 2 ; i <= N ; i++)
    {
        for (j = i-1 ; j >= (i+1)/2 ; j--)
            catalan[i] += catalan[j] * catalan[i-j-1] ;
        
        catalan[i] *= 2 ;
        if (i % 2)
            catalan[i] += catalan[i/2] * catalan[i/2] ;
    }
    
    cout << catalan[N] << "\n" ;
}

int main() 
{
	int noTest, N, i ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N ;
	    uniquebst (N) ;
	}
	return 0;
}
