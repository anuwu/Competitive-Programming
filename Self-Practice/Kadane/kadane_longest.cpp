// This is incorrect. Need to fix it.

#include <iostream>
#include <vector>

using namespace std ;

void kadane_longest (vector<int> A)
{
	// subSumi and subSumj themselves maintain the longest length subarray with maximum sum
	int subSumi, subSumj, endSumi, i ;
	int sum, sumEnd ;

	subSumi = subSumj = endSumi = 0;
	sum = sumEnd = A[0] ;
	for (i = 1 ; i < A.size () ; i++)
	{
		if (sumEnd < 0)
		{
			endSumi = i ;
			sumEnd = A[i] ;
		}
		else
			sumEnd += A[i] ;

		if (sum == sumEnd)
		{
			if (i - endSumi > subSumj - subSumi)
			{
				subSumi = endSumi ;
				subSumj = i ;
			}
		}
		else if (sumEnd > sum)
		{
			subSumi = endSumi ;
			subSumj = i ;
		}
		
	}

	printf ("The sub-array with largest length [%d, %d] with largest sum = %d\n", subSumi, subSumj, sum) ;
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

		kadane_longest (tc) ;
		tc.clear () ;
	}

	return 0 ;
}