#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void sortcolor (vector<int> &A)
{
    int i, lo, mid, hi, tmp, N = A.size () ;
    
    lo = mid = 0 ;
    hi = N-1 ;
    
    while (mid <= hi)
    {
        switch (A[mid])
        {
            case 0 :
                tmp = A[mid] ;
                A[mid] = A[lo] ;
                A[lo] = tmp ;
                
                lo++ ;
                mid++ ;
                break ;
                
            case 1 :
                mid++ ;
                break ;
                
            case 2 :
                tmp = A[hi] ;
                A[hi] = A[mid] ;
                A[mid] = tmp ;
                hi-- ;
                break ;
        }
    }
    
    for (i = 0 ; i < N ; i++)
        cout << A[i] << " " ;
    cout << "\n" ;
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
	    
	    sortcolor (tc) ;
	    tc.clear () ;
	}
	
	return 0;
}
