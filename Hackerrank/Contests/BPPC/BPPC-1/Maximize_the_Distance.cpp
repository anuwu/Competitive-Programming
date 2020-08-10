#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*
Tried solving with subset-sum with appropriate condition on the last-row. Too complex because
a particular sum can be obtained in multiple ways.
void maxDist (vector<int> &A)
{
    int i, j, maxsum, N = A.size() ;
    long long maxsq, sq ;
    
    maxsum = 0 ;
    for (i = 0 ; i < N ; i++)
        maxsum += A[i] ;
    
    
    vector<vector<bool>> dp (N, vector<bool> (maxsum+1, false)) ;
    vector<int> countmax (maxsum+1, 0) ;

    counts[0] = 0 ;
    for (i = 0 ; i < N ; i++)
        dp[i][0] = true ;

    dp[0][A[0]] = true ;
    counts[A[0]] = 1 ;
    
    for (i = 1 ; i < N ; i++)
    {
        for (j = 1 ; j <= maxsum ; j++)
        {
            if (A[i] > j)
                dp[i][j] = dp[i-1][j] ;
            else
            {
                dp[i][j] = dp[i-1][j-A[i]] || dp[i-1][j] ;
                if (dp[i-1][j-A[i]])
                    counts[j] = max(counts[j], counts[j-A[i]] + 1) ;
            }
        }
    }
    
    maxsq = INT_MIN ;
    for (j = 0 ; j <= maxsum ; j++)
    {
        if ((N % 2 && (counts[j] == N/2 || counts[j] == N/2 + 1)) || (N % 2 == 0 && counts[j] == N/2))
        {
            sq = (long long)j*(long long)j + ((long long)maxsum - j)*((long long)maxsum - j) ;
            if (sq > maxsq)
                    maxsq = sq ;
        }
    }
            
    cout << maxsq << "\n" ;
}
*/

void maxDist (vector<int> &A)
{
    int i, lim, N = A.size() ;
    long long one, two ;
    
    sort (A.begin(), A.end()) ;
    one = two = 0 ;
    
    lim = N/2 ;
    one = two = 0 ;
    
    for (i = N-1 ; i >= lim ; i--)
        two += A[i] ;
    
    for (i = 0 ; i < lim ; i++)
        one += A[i] ;
    
    cout << one*one + two*two << "\n" ;
}

int main() 
{
    int i, N ;
    vector<int> tc ;
    
    cin >> N ;
    tc = vector<int> (N, 0) ;
    for (i = 0 ; i < N ; i++)
        cin >> tc[i] ;
    
    maxDist (tc) ;
    
    return 0;
}

