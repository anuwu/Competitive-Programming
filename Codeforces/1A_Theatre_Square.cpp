#include <iostream>

using namespace std ;

int main ()
{
	long long n, m, a, ans ;

	cin >> n >> m >> a ;
	ans = (n/a + (n % a ? 1 : 0)) * (m/a + (m % a ? 1 : 0)) ;

	cout << ans << "\n" ;
	return 0 ;
}
