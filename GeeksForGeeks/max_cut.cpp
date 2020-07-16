#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void maxcuts (int length, vector<int> &A)
{
    if (A[0] > length || length == 0)
    {
        cout << 0 << "\n" ;
        return ;
    }
    
    int i, j, maxc, maxcdiv ;
    vector<int> dp (length + 1, 0) ;
    vector<int> dp1 (length + 1, 0) ;
    
    dp[A[0]] = 1 ;
    dp1[A[0]] = 1 ;
    for (i = A[0] + 1 ; i <= length ; i++)
    {
        maxc = INT_MIN ;
        maxcdiv = INT_MIN ;
        for (j = 0 ; j < 3 ; j++)
        {
            if (i - A[j] >= 0 && dp[i - A[j]] > maxc)
                maxc = dp[i - A[j]] ;
            if (i - A[j] >= 0 && dp[i - A[j]] > maxcdiv && dp1[i - A[j]])
                maxcdiv = dp[i - A[j]] ;
        }
        
        if (maxcdiv != INT_MIN)
        {
            dp[i] = maxcdiv + 1 ;
            dp1[i] = 1 ;
        }
        else if (i == A[1] || i == A[2])
        {
            dp[i] = 1 ;
            dp1[i] = 1 ;
        }
        else
            dp[i] = maxc + 1 ;
    }

    cout << dp[length] << "\n" ;
}

int main() 
{
	int noTest, length, in, i, j ;
	vector<int> tc ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> length ;
	    for (j = 0 ; j < 3 ; j++)
	    {
	        cin >> in ;
	        tc.push_back (in) ;
	    }
	    
	    sort (tc.begin(), tc.end()) ;
	    maxcuts (length, tc) ;
	    tc.clear () ;
	}
	
	return 0;
}
