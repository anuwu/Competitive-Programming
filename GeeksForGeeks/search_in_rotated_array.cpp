#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void sortedRotatedFind (vector<int> &A, int B)
{
	int l, r, mid, N, rot ;

	N = A.size() ;
	l = 0 ;
	r = N - 1 ;

	if (A[l] < A[r])
		rot = 0 ;
	else
	{
    	while (r - l > 1)
    	{
    		mid = (l+r)/2 ;
    		if (A[mid] == A[r])
    			r-- ;
    		else if (A[mid] >= A[l])
    		{
    			if (A[mid+1] >= A[mid])
    				l = mid + 1 ;
    			else if (A[r-1] > A[r])
    				l = mid ;
    			else
    				r-- ;
    		}
    		else
    			r = mid ;
    	}
    
    	if (A[l] != A[l+1])
    		rot = l+1 ;
    	else
    		rot = l ;
	}

	l = 0 ;
	r = N-1 ;
	while (l <= r)
	{
	    mid = (l+r)/2 ;
	    if (A[(mid+rot)%N] == B)
	    {
	        cout << (mid+rot)%N << "\n" ;
	        return ;
	    }
	    else if (B > A[(mid+rot)%N])
	        l = mid + 1 ;
	    else
	        r = mid - 1 ;
	}
	
	cout << -1 << "\n" ;
}

int main ()
{
	int noTest, N, in, find, i, j ;
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

        cin >> find ;
		sortedRotatedFind (tc, find) ;
		tc.clear () ;
	}

	return 0 ;
}
