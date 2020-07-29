#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sumEqSum (vector<int> &A)
{
    int i, j, sum, N = A.size() ;
    unordered_set<int> pairsum ;
    
    for (i = 0 ; i < N ; i++)
    {
        for (j = i+1 ; j < N ; j++)
        {
            sum = A[i] + A[j] ;
            if (pairsum.find (sum) != pairsum.end ())
            {
                cout << 1 << "\n" ;
                return ;
            }
            
            pairsum.insert (sum) ;
        }
    }
    
    cout << 0 << "\n" ;
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
	    
	    sumEqSum (tc) ;
	    tc.clear () ;
	}
	return 0;
}
