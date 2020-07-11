#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void minjumps (vector<int> &A)
{
    if (A.size () < 2)
    {
        cout << 0 << "\n" ;
        return ;
    }
    int i, maxreach, nextmax, jumps, N = A.size () ;
    
    jumps = 0 ;
    i = 0 ;
    maxreach = 0 ;
    while (true)
    {
        nextmax = maxreach ;
        for ( ; i <= maxreach ; i++)
            nextmax = max (nextmax, i + A[i]) ;
        
        if (nextmax == maxreach)
        {
            cout << -1 << "\n" ;
            return ;
        }
        
        jumps++ ;
        i = maxreach ;
        maxreach = nextmax ;
        if (maxreach >= N - 1)
        {
            cout << jumps << "\n" ;
            return ;
        }
    }
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
	    
	    minjumps (tc) ;
	    tc.clear () ;
	}
	return 0;
}
