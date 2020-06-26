// Vanilla kadane's algorithm simply maintaining index. 
/* Note - 	
1. This will ALWAYS generate the lexicographically smallest subarray
2. This will ALWAYS generate the shortest subarray
*/

#include <iostream>
#include <vector>

using namespace std ;

void kadane_index (vector<int> A)
{
	int subi, subj, endSumi, i ;
	int sum, sumEnd ;

	subi = subj = endSumi = 0 ;
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

		if (sumEnd > sum)
		{
			sum = sumEnd ;
			subi = endSumi ;
			subj = i ;
		}
	}

	printf ("The sub-array is [%d, %d] with largest sum = %d\n", subi, subj, sum) ;
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

		kadane_index (tc) ;
		tc.clear () ;
	}

	return 0 ;
}