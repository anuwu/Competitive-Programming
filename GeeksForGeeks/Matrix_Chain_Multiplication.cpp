#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void matrixchain (vector<int> &A)
{
    // N is the number of matrices plus 1
    // A[i] will represent the second dimension of the ith matrix (i is 1-indexed)
    
    int i, j, k, l, endmul, mul, minmul, N = A.size(), numMat = N-1 ;
    vector<vector<int>> dp (N, vector<int> (N, 0)) ;
    
    for (l = 2 ; l <= numMat ; l++)
    {
        for (i = 1 ; i <= N-l ; i++)
        {
            j = i + l - 1 ;
            minmul = INT_MAX ;
            endmul = A[i-1] * A[j] ;
            for (k = i ; k < j ; k++)
            {
                mul = dp[i][k] + dp[k+1][j] + endmul * A[k] ;
                if (mul < minmul)
                    minmul = mul ;
            }
            
            dp[i][j] = minmul ;
        }
    }

    cout << dp[1][numMat] << "\n" ;
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
        
        matrixchain (tc) ;
        tc.clear () ;
    }
	return 0;
}
