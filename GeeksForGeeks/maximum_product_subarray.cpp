#include <iostream>
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

void maxprod (vector<int> &A)
{
    if (A.size () == 1)
    {
        cout << A[0] << "\n" ;
        return ;
    }
    
    int i, N = A.size() ;
    long long maxend, minend, maxp, minp, tmp ;
    
    maxend = minend = maxp = minp = 0 ;
    if (A[0] > 0)
        maxend = maxp = A[0] ;
    else
        minend = minp = A[0] ;
    
    for (i = 1 ; i < N ; i++)
    {
        if (A[i] == 0)
            maxend = minend = 0 ;
        else if (A[i] > 0)
        {
            if (maxend == 0 && minend == 0)
                maxend = A[i] ;
            else if (maxend == 0 && minend != 0)
            {
                maxend = A[i] ;
                minend = -(((-minend) * (A[i] % MOD)) % MOD) ;
            }
            else if (maxend != 0 && minend == 0)
                maxend = (maxend * (A[i] % MOD)) % MOD ;
            else
            {
                maxend = (maxend * (A[i] % MOD)) % MOD ;
                minend = -(((-minend) * (A[i] % MOD)) % MOD) ;
            }
        }
        else
        {
            if (maxend == 0 && minend == 0)
                minend = A[i] ;
            else if (maxend == 0 && minend != 0)
            {
                maxend = ((-minend) * ((-A[i]) % MOD)) % MOD ;
                minend = A[i] ;
            }
            else if (maxend != 0 && minend == 0)
            {
                minend = -((maxend * ((-A[i]) % MOD)) % MOD) ;
                maxend = 0 ;
            }
            else
            {
                tmp = minend ;
                minend = -((maxend * ((-A[i]) % MOD)) % MOD) ;
                maxend = ((-tmp) * ((-A[i]) % MOD)) % MOD ;
            }
        }
        
        maxp = max (maxp, maxend) ;
        minp = min (minp, minend) ;
    }
    
    cout << (int)maxp << "\n" ;
}

int main() 
{
	int noTest, N, in, i, j ;
	vector<int> tc ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N ;
	    for (j = 0 ; j < N ; j++)
	    {
	        cin >> in ;
	        tc.push_back (in) ;
	    }
	    
	    maxprod (tc) ;
	    tc.clear () ;
	}
	return 0;
}
