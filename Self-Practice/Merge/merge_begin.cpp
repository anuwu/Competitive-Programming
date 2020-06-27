#include <iostream>
#include <vector>

using namespace std ;

void merge_begin (vector<int> &A, vector<int> &B) 
{
    int i, j, lenA, lenB ;
    
    lenA = A.size () ;
    lenB = B.size () ;
    
    if (A[lenA - 1] <= B[0])
    {
        A.insert (A.end (), B.begin (), B.end ()) ;
        return ;
    }
    else if (B[lenB - 1] <= A[0])
    {
        A.insert (A.begin (), B.begin (), B.end ()) ;
        A = B ;
        return ;
    }
    
    i = 0 ;
    j = 0 ;
    do
    {
        while (i < A.size () && B[j] > A[i])
            i++ ;
        
        if (i == A.size ())
        {
            A.insert (A.end (), B.begin () + j,  B.end ()) ;
            break ;
        }

        A.insert (A.begin () + i, B[j]) ;
        i++ ;
        j++ ;
        
        
        if (j == lenB)
            break ;
    } while (true) ;
}

int main ()
{
	vector<int> A, B
	int szA, szB, in, i ;

	cin >> szA ;
	for (i = 0 ; i < szA ; i++)
	{
		cin >> in ;
		A.push_back (in) ;
	}

	cin >> szB ;
	for (i = 0 ; i < szB ; i++)
	{
		cin >> in ;
		B.push_back (in) ;
	}

	merge_begin (A, B) ;
	cout << "The merged vector - \n" ;
	for (i = 0 ; i < szA + szB ; i++)
		cout << A[i] << " " ;
	cout << "\n" ;

	return 0 ;
}