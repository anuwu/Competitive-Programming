// Works for unique elements. Checked by leetcode!

#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void sortedRotation (vector<int> &A)
{
	int l, r, mid, drop, last, N ;

	N = A.size() ;
	l = 0 ;
	r = 2*N - 1 ;

	if (A[0] < A[N-1])
	{
		printf ("Sorted array starts at A[%d] = %d\n", 0, A[0]) ;
		return ;
	}
	else
	{
		l = N ;
		last = A[N-1] ;
	}

	while (l <= r)
	{
		mid = (l+r)/2 ;
		drop = (mid + 1) % N ;
		//printf ("l=%d, r=%d, Finding A[%d] = %d\n", l%N, r%N, mid % N, A[mid % N]) ;
		if (A[drop] < A[mid % N])
		{
			printf ("Sorted array starts at A[%d] = %d\n", drop, A[drop]) ;
			return ;
		}
		else if (A[mid % N] > last)
		{
			last = A[mid % N] ;
			l = mid + 1 ;
		}
		else
		{
			last = A[mid % N] ;
			r = mid - 1 ;

			if (A[r%N] > A[mid%N])
			{
				printf ("Sorted array starts at A[%d] = %d\n", mid%N, A[mid%N]) ;
				return ;
			}
		}
	}

	if (A[(l+1)%N] == A[0])
		printf ("Sorted array starts at A[%d] = %d\n", l % N, A[l % N]) ;
	else
		printf ("Sorted array starts at A[%d] = %d\n", (l+1) % N, A[(l+1) % N]) ;
	
	return ;
}


int main ()
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

		sortedRotation (tc) ;
		tc.clear () ;
	}

	return 0 ;
}