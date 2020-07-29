#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void stockSpan (vector<int> &A)
{
    int i, sp,  N = A.size() ;
    
    vector<int> span (N, 1) ;
    stack<pair<int,int>> s ;
    pair<int, int> p ;
    
    s.push (make_pair (A[0], 0)) ;
    span[0] = 1 ;
    for (i = 1 ; i < N ; i++)
    {
        sp = 0 ;
        while (!s.empty() && s.top().first <= A[i])
        {
            sp += span[s.top().second] ;
            s.pop () ;
        }
        sp++ ;
        
        span[i] = sp ;
        s.push (make_pair (A[i], i)) ;
    }
    
    for (i = 0 ; i < N ; i++)
        cout << span[i] << " " ;
    cout << "\n" ;
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
	    
	    stockSpan (tc) ;
	    tc.clear () ;
	}
	
	return 0;
}
