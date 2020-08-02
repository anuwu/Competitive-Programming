#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void coinpiles (vector<int> A, int K)
{
    int i, j, removed, minCnt, cnt, N = A.size() ;
    
    sort (A.begin(), A.end()) ;
    removed = 0 ;
    minCnt = INT_MAX ;
    for (i = 0 ; i < N ; i++)
    {
        removed += (i-1 >= 0) ? A[i-1] : 0 ;
        cnt = removed ;
        
        j = N-1 ;
        while (j > i && A[j] - A[i] > K)
        {
            cnt += A[j] - (A[i] + K) ;
            j-- ;
        }
        
        minCnt = min (minCnt, cnt) ;
    }
    
    cout << minCnt << "\n" ;
    
}

int main() 
{
	int noTest, N, K, in ;
	vector<int> tc ;
	
	cin >> noTest ;
	while (noTest--)
	{
	    cin >> N >> K ;
	    while (N--)
	    {
	        cin >> in ;
	        tc.push_back (in) ;
	    }
	    
	    coinpiles (tc, K) ;
	    tc.clear () ;
	}
	return 0;
}
