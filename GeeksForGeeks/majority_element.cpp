#include <stdio.h>
#include <bits/stdc++.h>

using namespace std ;

void majority (vector<int> &A)
{
    int i, maxi, cnt, N = A.size() ;
    
    maxi = 0 ;
    cnt = 1 ;
    for (i = 1 ; i < N ; i++)
    {
        if (A[i] == A[maxi])
            cnt++ ;
        else
            cnt-- ;
            
        if (!cnt)
        {
            maxi = i ;
            cnt = 1 ;
        }
    }
    
    cnt = 0 ;
    for (i = 0 ; i < N ; i++)
        if (A[i] == A[maxi])
            cnt++ ;
            
    if (cnt > N/2)
        cout << A[maxi] << "\n" ;
    else
        cout << -1 << "\n" ;
}

int main() 
{
    int noTest, N ;
    
    cin >> noTest ;
    do
    {
        cin >> N ;
        vector<int> tc (N, 0) ;
        for (int i = 0 ; i < N ; i++)
            cin >> tc[i] ;
            
        majority (tc) ;
        tc.clear () ;
    } while (--noTest) ;
	return 0;
}
