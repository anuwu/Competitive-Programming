#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void coinchange (vector<int> &A, int cents)
{
    int i, j, N = A.size() ;
    vector<vector<int>> dp (cents+1, vector<int> (N, 0)) ;
    
    for (j = 0 ; j < N ; j++)
        dp[0][j] = 1 ;
        
    for (i = 1 ; i <= cents ; i++)
    {
        for (j = 0 ; j < N ; j++)
        {
            dp[i][j] += (i - A[j] >= 0) ? dp[i-A[j]][j] : 0 ;
            dp[i][j] += (j >= 1) ? dp[i][j-1] : 0 ; 
        }
    }
    
    cout << dp[cents][N-1] << "\n" ;
}

int main() 
{
	int noTest, N, cents, in, i, j ;
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
	    
	    cin >> cents;
	    coinchange (tc, cents) ;
	    tc.clear () ;
	}
	return 0;
}
