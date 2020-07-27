#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void binarySort (vector<int> &A)
{
    int i, lo, hi, tmp, N = A.size() ;
    
    lo = 0 ;
    hi = N-1 ;
    while (lo <= hi)
    {
        if (A[lo] == 1)
        {
            tmp = A[lo] ;
            A[lo] = A[hi] ;
            A[hi] = tmp ;
            hi-- ;
        }
        else
            lo++ ;
    }
    
    for (i = 0 ; i < N ; i++)
        cout << A[i] << " " ;
    cout << "\n" ;
}


using namespace std ;
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
        
        binarySort (tc) ;
        tc.clear () ;
    }
    
    
	return 0;
}
