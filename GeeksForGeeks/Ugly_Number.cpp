#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<long long> uglies ;

void ugly (int N)
{
    int i, i2, i3, i5, n2, n3, n5, tmp ;
    uglies = vector<long long> (N, 0) ;
    
    uglies[0] = 1 ;
    i2 = i3 = i5 = 0 ;
    n2 = 2 ;
    n3 = 3 ;
    n5 = 5 ;
    for (i = 1 ; i < N ; i++)
    {
        uglies[i] = min (n2, min (n3, n5)) ;
        
        if (uglies[i] == n2)
        {
            i2++ ;
            n2 = uglies[i2]*2 ;
        }
        if (uglies[i] == n3)
        {
            i3++ ;
            n3 = uglies[i3]*3 ;
        }
        if (uglies[i] == n5)
        {
            i5++ ;
            n5 = uglies[i5]*5 ;
        }
    }
}


int main() 
{
	int noTest, N, i ;
	
	uglies.clear () ;
	ugly (10000) ;
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N ;
	    cout << abs(uglies[N-1]) << "\n" ;
	}
	
	return 0;
}

