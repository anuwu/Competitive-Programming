#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void minCoins (vector<int> &A, int V)
{
    int i, j, N = A.size() ; ;
    vector<int> dp (V+1, INT_MAX) ;
    
    dp[0] = 0 ;
    for (i = 1 ; i <= V ; i++)
    {
        for (j = 0 ; j < N ; j++)
        {
            if (i - A[j] >= 0)
                dp[i] = min (dp[i], dp[i - A[j]] == INT_MAX ? INT_MAX : dp[i - A[j]] + 1) ;
        }
                
    }
    
    if (dp[V] == INT_MAX)
        cout << -1 << "\n" ;
    else
        cout << dp[V] << "\n" ;
}


int main() 
{
	int noTest, V, N, in, i, j ;
	vector<int> tc ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> V >> N ;
	    for (j = 0 ; j < N ; j++)
	    {
	        cin >> in ;
	        tc.push_back (in) ;
	    }
	    
	    minCoins (tc, V) ;
	    tc.clear () ;
	}
	return 0;
}
