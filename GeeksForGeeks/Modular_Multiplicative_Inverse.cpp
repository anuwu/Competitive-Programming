#include <iostream>
using namespace std;

int extgcd (int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0 ;
        *y = 1 ;
        return b ;
    }
    
    int x1, y1, gcdval ;
    gcdval = extgcd (b % a, a, &x1, &y1) ;
    *y = x1 ;
    *x = y1 - (b/a) * x1 ;
    
    return gcdval ;
}


void modInv (int a, int m)
{
    int gcd, x, y ;
    
    gcd = extgcd (a, m, &x, &y) ;
    if (gcd != 1)
    {
        cout << -1 << "\n" ;
        return ;
    }

    x = (x < 0) ? m + x : x ;
    cout << x << "\n" ;
}

int main() 
{
	int noTest, a, b ;
	
	cin >> noTest ;
	do
	{
	    cin >> a >> b ;
	    modInv (a, b) ;
	    
	} while (--noTest) ;
	return 0;
}
