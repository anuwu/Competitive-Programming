#include <iostream>
#include <math.h>
using namespace std;


void largestpf (long long n)
{
    int i = 3 ;
    
    while (n % 2 == 0)
        n /= 2 ;
        
    if (n == 1)
    {
        cout << 2 << "\n" ;
        return ;
    }

    while (i*i <= n)
    {
        while (n % i == 0)
            n /= i ;
            
        i += 2 ;
    }
    
    if (n != 1)
        cout << n << "\n" ;
    else
        cout << i-2 << "\n" ;
}

int main() 
{
	int noTest, i ;
	long long n ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> n ;
	    largestpf (n) ;
	}
	return 0;
}
