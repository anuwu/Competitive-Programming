#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void largestSqSubmat (vector<vector<int>> &A)
{
    int i, j, ans, R = A.size(), C = A[0].size() ;
    
    vector<vector<int>> dp (R, vector<int> (C, 0)) ;
    
    ans = 0 ;
    for (i = 0 ; i < R ; i++)
    {
        if (A[i][0])
        {
            dp[i][0] = 1 ;
            ans = 1 ;
        }
    }
            
    for (j = 0 ; j < C ; j++)
    {
        if (A[0][j])
        {
            dp[0][j] = 1 ;
            ans = 1 ;
        }
    }
            
    for (i = 1 ; i < R ; i++)
    {
        for (j = 1 ; j < C ; j++)
        {
            if (A[i-1][j-1] == 0)
                dp[i][j] = A[i][j] ;
            else if (A[i][j])
            {
                if (A[i-1][j] == 0 || A[i][j-1] == 0)
                    dp[i][j] = A[i][j] ;
                else
                {
                    //dp[i][j] = min (dp[i-1][j], dp[i][j-1]) + 1 ;
                    //dp[i][j] = dp[i-1][j-1] + 1 ;
                    dp[i][j] = min (dp[i-1][j-1], min (dp[i][j-1], dp[i-1][j])) + 1 ;
                    
                    if (dp[i][j] > ans)
                        ans = dp[i][j] ;
                }
                
            }
        }
    }
    
    cout << ans << "\n" ;
}

int main() 
{
	int noTest, R, C, in, i, j, k ;
	vector<vector<int>> mat ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> R >> C ;
	    mat = vector<vector<int>> (R, vector<int> (C)) ;
	    for (j = 0 ; j < R ; j++)
	    {
	        for (k = 0 ; k < C ; k++)
	        {
	            cin >> in ;
	            mat[j][k] = in ;
	        }
	    }
	    
	    largestSqSubmat (mat) ;
	    mat.clear () ;
	}
	
	return 0;
}
