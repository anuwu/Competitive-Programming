#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

void secondSmall (vector<int> &A)
{
    int min1, min2, i ;
    
    min1 = A[0] ;
    min2 = INT_MAX ;
    for (i = 1 ; i < A.size () ; i++)
    {
        if (A[i] < min1)
        {
            min2 = min1 ;
            min1 = A[i] ;
        }
        else if (A[i] < min2 && A[i] > min1)
            min2 = A[i] ;
    }
    
    if (min2 == INT_MAX)
        cout << -1 << "\n" ;
    else
        cout << min1 << " " << min2 << "\n" ;
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
	    
	    secondSmall (tc) ;
	    tc.clear () ;
	}
	return 0;
}
