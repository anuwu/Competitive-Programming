#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

string yes ("ambiguous") ;
string no ("not ambiguous") ;

void isAmbi (vector<int> &A)
{
    int i, N = A.size() ;
    
    i = 0 ;
    do
    {
        if (i + 1 != A[A[i] - 1])
        {
            cout << no << "\n" ;
            return ;
        }
        
        i++ ;
    } while (i < N) ;
    
    cout << yes << "\n" ;
}

int main() 
{
    int i, N ;
    do
    {
        cin >> N ;
        if (!N)
            break ;
           
        vector<int> tc (N, 0) ;
        for (i = 0 ; i < N ; i++)
            cin >> tc[i] ;
            
        isAmbi (tc) ;
        tc.clear() ;
    } while (true) ;
    
	return 0;
}

