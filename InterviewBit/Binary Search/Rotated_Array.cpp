int Solution::findMin(const vector<int> &A) 
{
   int l, r, mid, N, fin ;

	N = A.size() ;
	l = 0 ;
	r = N - 1 ;

	if (A[l] < A[r])
		return A[0] ;
	while (r - l > 1)
	{
		mid = (l+r)/2 ;
		if (A[mid] > A[l])
		{
			if (A[mid+1] > A[mid])
				l = mid + 1 ;
			else if (A[r-1] > A[r])
				l = mid ;
			else
				r-- ;
		}
		else
			r = mid ;
	}

	return A[r] ;
}

