// Failed attempt. Don't look!

#include <iostream>
#include <bits/stdc++.h>

int minPeak ;

bool isFlatAt (vector<int> &A, int x, int flatline)
{
	return A[x-1] == A[x] && A[x] == A[x+1] && A[x] == flatline ;
}

char searchDecrDir (vector<int> &A)
{
	int l, r, mid, lmid, rmid, N, flatline ;
	char rdir, ldir ;

	N = A.size() ;
	flatline = A[N/2] ;
	l = N/2 ;
	r = N-1 ;
	while (l <= r)
	{
		mid = (l+r)/2 ;
		if (mid < N - 1 && isFlatAt (A, mid, flatline))
			l = mid + 1 ;
		else if (mid >= N - 1)
		{
			rdir = 'f' ;
			break ;
		}
		else
		{

			if (A[mid] > flatline)
				rdir = 'i' ;
			else if (A[mid] < flatline)
				rdir = 'd' ;
			else if (A[mid+1] > A[mid])
				rdir = 'i' ;
			else
				rdir = 'd' ;

			rmid = mid ;
			break ;
		}
	}


	l = 0 ;
	r = N/2 ;
	while (l <= r)
	{
		mid = (l+r)/2 ;
		if (l > 0 && isFlatAt (A, mid, flatline))
			r = mid - 1 ;
		else if (l <= 0)
		{
			ldir = 'f' ;
			break ;
		}
		else
		{
			if (A[mid] > flatline)
				ldir = 'i' ;
			else if (A[mid] < flatline)
				ldir = 'd' ;
			else if (A[mid-1] > A[mid])
				ldir = 'i' ;
			else
				ldir = 'd' ;

			lmid = mid ;
			break ;
		}
	}

	if (ldir == 'f' && rdir == 'f')
		return 'f' ;

	if (ldir == 'f')
	{
		if (rdir == 'i')
			minPeak = 0 ;
		else
			minPeak = N-1 ;

		return 'p' ;
	}

	if (rdir == 'f')
	{
		if (ldir =='i')
			minPeak = N-1 ;
		else
			minPeak = 0 ;

		return 'p' ;
	}

	if (ldir == 'd' && rdir == 'd')
	{
		minPeak = rmid + 1 ;
		return 'p' ;
	}
	else if (ldir == 'd' && rdir == 'i')
		return 'l' ;
	else if (ldir == 'i' && rdir == 'd')
		return 'r' ;
	else
	{
		minPeak = lmid - 1 ;
		return 'p' ;
	}
}

void sorted_minPeak (vector<int> &A)
{
	if (A.size() == 1)
	{
		cout << 0 << " " << A[0] << "\n" ;
		return ;
	}
	else if (A.size() == 2)
	{
		if (A[1] < A[0])
			cout << 1 << " " << A[1] << "\n" ;
		else
			cout << 0 << " " << A[0] << "\n" ;

		return ;
	}

	int l, r, mid, N ;
	char dir ;

	peak = -1 ;
	N = A.size() ;
	l = 0 ;
	r = N - 1 ;
	mid = (l + r)/2 ;

	if (A[mid-1] > A[mid] && A[mid] <= A[mid+1])
	{
		cout << mid << " " << A[mid] << "\n" ;
		return ;
	}


	if (A[mid-1] < A[mid])
		dir = 'l' ;
	else if (A[mid-1] == A[mid])
	{
		if (A[mid+1] < A[mid])
			dir = 'r' ;
		else if (A[mid+1] > A[mid])
			dir = 'l' ;
		else
		{
			dir = searchDecrDir (A) ;
			if (dir == 'p')
			{
				cout << minPeak << " " << A[minPeak] << "\n" ;
				return ;
			}
		}
	}
	else	
		dir = 'r' ;

	
}

int main ()
{
	int noTest, N, in, i, j ;
	vector<int> tc ;

	for (i = 0 ; i < noTest ; i++)
	{
		cin >> N ;
		for (j = 0 ; j < N ; j++)
		{
			cin >> in ;
			tc.push_back (in) ;
		}

		sorted_minPeak (tc) ;
		tc.clear () ;
	}

	return 0 ;
}