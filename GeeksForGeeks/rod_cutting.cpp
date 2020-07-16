#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rodcut (vector<int> &A)
{
    int i, j, maxcost, N = A.size() ;
    vector<int> dp (N+1, 0) ;
    
    dp[1] = A[0] ;
    for (i = 2 ; i <= N ; i++)
    {
        maxcost = A[i-1] ;
        for (j = 1 ; j < i/2 + 1 + (i % 2 ? 1 : 0) ; j++)
        {
            if (dp[j] + dp[i-j] > maxcost)
                maxcost = dp[j] + dp[i-j] ;
        }
        
        dp[i] = maxcost ;
    }
    
    cout << dp[N] << "\n" ;
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
        
        rodcut (tc) ;
        tc.clear () ;
    }
	return 0;
}
