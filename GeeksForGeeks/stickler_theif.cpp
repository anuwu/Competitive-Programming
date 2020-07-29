#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void thief (vector<int> &A)
{
    int i, N = A.size() ;
    int incl = A[0], excl = 0, tmpincl, tmpexcl ;
    
    for (i = 1 ; i < N ; i++)
    {
        tmpincl = excl + A[i] ;
        excl = max (excl, incl) ;
        incl = tmpincl ; 
    }
    
    cout << ((excl > incl) ? excl : incl) << "\n" ;
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
	    
	    thief (tc) ;
	    tc.clear () ;
	}
	return 0;
}
