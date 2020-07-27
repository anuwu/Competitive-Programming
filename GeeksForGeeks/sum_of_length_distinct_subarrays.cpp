#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void distinctSubLength (vector<int> &A)
{
    int i, j, rep, sublen, sum, N = A.size() ;
    unordered_map<int, int> m ;
    
    sum = 0 ;
    i = 0 ;
    for (j = 0 ; j < N ; j++)
    {
        if (m.find (A[j]) != m.end ())
        {
            rep = m[A[j]] ;
            for (; i <= rep ; i++)
                m.erase (A[i]) ;
                
            sum += ((j - rep)*(j - rep + 1))/2 ;
        }
        else
            sum += ((j - i + 1) * (j - i + 2))/2 ;
            
        
        m[A[j]] = j ;
    }
    
    cout << sum << "\n" ;
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
	    
	    distinctSubLength (tc) ;
	    tc.clear () ;
	}
	return 0;
}
