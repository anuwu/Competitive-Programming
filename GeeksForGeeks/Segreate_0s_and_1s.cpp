#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void binarySort (vector<int> &A)
{
    int i, j, x, piv, tmp, N = A.size() ;
    
    for (x = N-1 ; x >= 0 ; x--)
        if (!A[x])
            break ;
            
    if (x <= 0)
        goto here ;
    
    piv = A[x] ;
    
    i = -1 ;
    for (j = 0 ; j < x ; j++)
    {
        if (A[j] <= piv)
        {
            i++ ;
            tmp = A[i] ;
            A[i] = A[j] ;
            A[j] = tmp ;
        }
    }
    
    i++ ;
    tmp = A[i] ;
    A[i] = A[x] ;
    A[x] = tmp ;
    
    here :
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
        
        binarySort (tc) ;
        tc.clear () ;
    }
    
    
	return 0;
}
