#include <iostream>
#include <vector>

using namespace std ;

void merge_end (vector<int> &A, vector<int> &B) 
{
    int i, j, lenA, lenB ;
    
    lenA = A.size () ;
    lenB = B.size () ;
    
    i = lenA - 1 ;
    j = lenB - 1 ;  
    do
    {
        while (i >= 0 && A[i] > B[j])
            i-- ;
        
        if (i < 0)
        {
            A.insert (A.begin(), B.begin (), B.begin () + j + 1) ;
            break ;
        }
        
        A.insert (A.begin () + i + 1 , B[j]) ;
        j-- ;
        if (j < 0)
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

	merge_end (A, B) ;
    cout << "The merged vector - \n" ;
    for (i = 0 ; i < szA + szB ; i++)
        cout << A[i] << " " ;
    cout << "\n" ;
    
	return 0 ;
}