// Check kadane_index for details

#include <iostream>
#include <vector>

using namespace std ;

void kadane_lexico_strict (vector<int> A)
{
	// subSumi and subSumj themselves maintain the lexicographically lowest maximum subarray sum
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

		// This condition is probably redundant. endSumi < subSumi will ALWAYS be true.
		/*
			[0 1 2 3      ....   .  ]
				 ^				 ^
				 endSumi 		 i

			Lexicographic ordering matters only when `sum` = `sumEnd`
			The only way sumEnd is updated is by keeping up `endSumi` with `i`. Hence, it can never 
			become smaller than `subSumi`

			On the other end, if the sum does get updated, `subSumi` is refreshed with `endSumi` and
			the process can repeat

		if (sum == sumEnd)
		{
			if (endSumi < subSumi)
			{
				subSumi = endSumi ;
				subSumj = i ;
			}
		}
		else*/ if (sumEnd > sum)
		{
			sum = sumEnd ;
			subSumi = endSumi ;
			subSumj = i ;
		}
		
	}

	printf ("The lexicographically smallest subarray is [%d, %d] with largest sum = %d\n", subSumi, subSumj, sum) ;
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

		kadane_lexico_strict (tc) ;
		tc.clear () ;
	}

	return 0 ;
}