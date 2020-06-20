#include <iostream>
#include <vector>

using namespace std;

void sieve (int N)
{
    int i, p, st ;
    vector<bool> arr(N , false) ;
    
    p = 2 ;
    st = p*p ;
    while (st <= N)
    {
        while (st <= N)
        {
            arr[st - 1] = true ;
            st += p ;
        }
        
        do p++ ; while (arr[p - 1]) ;
            
        st = p*p ;    
    }
    
    for (i = 1 ; i < N ; i++)
        if (!arr[i])
            cout << i + 1 << " " ;
            
    cout << "\n" ;
}

int main() 
{
	int i, N, T ;
	
	cin >> T ;
	for (i = 0 ; i < T ; i++)
	{
	    cin >> N ;
	    sieve (N) ;
	}
	return 0 ;
}