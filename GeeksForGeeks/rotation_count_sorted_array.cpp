#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

void sortedRotation (vector<int> &A)
{
	int l, r, mid, N, fin ;

	N = A.size() ;
	l = 0 ;
	r = N - 1 ;

	if (A[l] < A[r])
	{
		cout << 0 << "\n" ;
		return ;
	}

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
		fin = l+1 ;
	else
		fin = l ;

	cout << fin << "\n" ;
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

