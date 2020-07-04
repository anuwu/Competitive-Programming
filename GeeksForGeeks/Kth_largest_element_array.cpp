#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void klargest (vector<int> &A, int K)
{
    int i, cnt ;
    map<int, int, greater<int>> m ;
    map<int, int, greater<int>>::iterator it ;
    
    for (i = 0 ; i < A.size () ; i++)
    {
        if (m.find (A[i]) == m.end ())
            m[A[i]] = 1 ;
        else
            m[A[i]]++ ;
    }
        
    it = m.begin () ;
    cnt = 0 ;
    do
    {
        if (cnt + it->second <= K)
        {
            for (i = 0 ; i < it->second ; i++)
                cout << it->first << " " ;
            
            cnt += it->second ;
        }
        else
        {
            for (i = 0 ; i < K - cnt ; i++)
                cout << it->first << " " ;
                
            break ;
        }
        
        it++ ;
        if (it == m.end ())
            break ;
    } while (cnt != K) ;
    
    cout << "\n" ;
}

int main() 
{
	int noTest, N, K, in, i, j ;
	vector<int> tc ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N >> K ;
	    for (j = 0 ; j < N ; j++)
	    {
	        cin >> in ;
	        tc.push_back (in) ;
	    }
	    
	    klargest (tc, K) ;
	    tc.clear () ;
	}
	return 0;
}
