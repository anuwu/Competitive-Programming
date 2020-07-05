#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void sortedRotation (vector<int> &A)
{
	int l, r, mid, N, fin ;

	N = A.size() ;
	l = 0 ;
	r = N - 1 ;


	/**************************************************************
	* For a rotated array, we know that A[l] >= A[r] must be true.
	* Hence if that is violated, there is no rotation to the array

	* The only other way in which A[l] >= A[r] and there is zero 
	* rotation is if all the array elements are identical. This case
	* can be detected if l is forward to equal r (or exceed it).
	***************************************************************/
	if (A[l] < A[r])
	{
		printf ("Sorted array starts at A[%d] = %d\n", 0, A[0]) ;
		return ;
	}

	while (r - l > 1)
	{
		mid = (l+r)/2 ;
		printf ("%d, %d, %d\n", l, mid, r) ;
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
		fin = l+1 ;
	else
		fin = l ;

	printf ("Sorted array starts at A[%d] = %d\n", fin, A[fin]) ;
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
