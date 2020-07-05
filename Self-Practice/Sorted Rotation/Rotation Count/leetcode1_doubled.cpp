int findMin(vector<int>& A) 
{
	int l, r, mid, drop, last, N ;

	N = A.size() ;
	l = 0 ;
	r = 2*N - 1 ;

	if (A[0] < A[N-1])
		return A[0] ;
	else
	{
		l = N ;
		last = A[N-1] ;
	}

	while (l <= r)
	{
		mid = (l+r)/2 ;
		drop = (mid + 1) % N ;
		if (A[drop] < A[mid % N])
			return A[drop] ;
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
				return A[mid%N] ;
		}
	}

	if (A[(l+1)%N] == A[0])
		return A[l % N] ;
	else
		return A[(l+1) % N] ;
}
