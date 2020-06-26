// This is incorrect. Need to fix it.

#include <iostream>
#include <vector>

using namespace std ;

void kadane_lexico_longest (vector<int> A)
{
	// subSumi and subSumj themselves maintain the lexicographically lowest, longest length, maximum subarray sum
	int subSumi, subSumj, endSumi, i, length ;
	int sum, sumEnd ;

	subSumi = subSumj = endSumi = 0;
	sum = sumEnd = A[0] ;
	for (i = 1 ; i < A.size () ; i++)
	{
		// This will create problems. 
		if (sumEnd < 0)
		{
			endSumi = i ;
			sumEnd = A[i] ;
		}
		else
			sumEnd += A[i] ;

		if (sum == sumEnd)
		{
			// No need of endSumi <= subSumi as the < condition can never occur
			if (endSumi == subSumi)
				subSumj = i ;
		}
		else if (sumEnd > sum)
		{
			sum = sumEnd ;
			subSumi = endSumi ;
			subSumj = i ;
		}
		
	}

	printf ("The lexicographically smallest subarray with largest length is [%d, %d] with largest sum = %d\n", subSumi, subSumj, sum) ;
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

		kadane_lexico_longest (tc) ;
		tc.clear () ;
	}

	return 0 ;
}