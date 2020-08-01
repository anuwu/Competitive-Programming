#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void lps (string &A)
{
    int i, j, l, pallen, pali, palj, L = A.length(); 
    vector<vector<bool>> dp (L, vector<bool> (L, false)) ;
    
    pallen = 1 ;
    pali = palj = 0 ;
    for (i = 0 ; i < L ; i++)
        dp[i][i] = true ;
        
    for (i = 0 ; i < L-1 ; i++)
    {
        if (A[i] == A[i+1])
        {
            dp[i][i+1] = true ;
            if (pallen == 1)
            {
                pallen = 2 ;
                pali = i ;
                palj = i+1 ;
            }
        }
    }
            
    for (l = 3 ; l <= L ; l++)
    {
        for (i = 0 ; i <= L-l ; i++)
        {
            j = i + l - 1 ;
            if (A[i] == A[j] && dp[i+1][j-1])
            {
                dp[i][j] = true ; 
                if (j-i+1 > pallen)
                {
                    pallen = j-i+1 ;
                    pali = i ;
                    palj = j ;
                }
            }
        }
    }
    
    cout << A.substr (pali, palj - pali + 1) << "\n" ;
}

int main() 
{
	int noTest, i ;
	string str ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> str ;
	    lps (str) ;
	}
	return 0;
}
