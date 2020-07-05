#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rainWater (vector<int> &A)
{
    int water, N, i, base, height ;
    stack<pair<int,int>> st ;
    
    N = A.size() ;
    water = 0 ;
    i = 0 ;
    while (i < N - 1 && A[i+1] >= A[i])
        i++ ;
        
    if (i >= N - 2)
    {
        cout << 0 << "\n" ;
        return ;
    }
    
    st.push (make_pair (A[i], i)) ;
    i++ ;
    for ( ; i < N ; i++)
    {
        if (A[i] > st.top().first)
        {
            base = st.top().first ;
            st.pop () ;
            while (!st.empty() && A[i] > st.top().first)
            {
                height = st.top().first ;
                water += (height - base) * (i - st.top().second - 1) ;
                base = height ;
                
                st.pop () ;
            } 
            
            if (!st.empty ())
                water += (A[i] - base) * (i - st.top().second - 1) ;
        }
        
        st.push (make_pair (A[i], i)) ;
    }
    
    cout << water << "\n" ;
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
	    
	    rainWater (tc) ;
	    tc.clear () ;
	}
	return 0;
}
