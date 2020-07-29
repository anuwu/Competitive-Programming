#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void wines (vector<int> &A)
{
    if (!A.size())
    {
        cout << 0 << "\n" ;
        return ;
    }
    else if (A.size() == 1)
    {
        cout << A[0] << "\n" ;
        return ;
    }
    
    int i, j, maxsum, N = A.size() ;
    vector<vector<int>> dp (N, vector<int> (N, 0)) ;
    
    dp[0][N-1] = 0 ;
    for (i = N-2 ; i > 0 ; i--)
        dp[0][i] = dp[0][i+1] + A[i+1]* (N-1-i) ;
        
    for (i = 1 ; i < N ; i++)
        dp[i][N-1] = dp[i-1][N-1] + A[i-1] * i ;
        
    for (i = 1 ; i < N-1 ; i++)
        for (j = N-2 ; j >= i ; j--)
            dp[i][j] = max (dp[i-1][j] + A[i-1]*(N-(j-i+1)),  dp[i][j+1] + A[j+1]*(N-(j-i+1))) ;
    
    maxsum = INT_MIN ;
    for (i = 0 ; i < N ; i++)
        if (dp[i][i] + A[i]*N > maxsum)
            maxsum = dp[i][i] + A[i]*N ;
    
    
    cout << maxsum << "\n" ;
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
        
        wines (tc) ;
        tc.clear () ;
    }
    
}
