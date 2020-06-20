#include <iostream>
#include <vector>

using namespace std ;


void missing (vector<int> &arr, int N)
{
    int x1, x2 ;
    x1 = 1 ;
    
    for (int i = 2 ; i <= N ; i++)
        x1 ^= i ;
        
    x2 = arr[0] ;
    for (int i = 1 ; i < arr.size () ; i++)
        x2 ^= arr[i] ;
        
    cout << (x1^x2) << "\n" ;
}

int main() 
{
	int i, j, noTest, N, in ;
	vector<int> arr ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N ;
	    for (j = 0 ; j < N - 1 ; j++)
	    {
	        cin >> in ;
	        arr.push_back (in) ;
	    }
	    
	    missing (arr, N) ;
	    arr.clear () ;
	}
	
	return 0;
}
