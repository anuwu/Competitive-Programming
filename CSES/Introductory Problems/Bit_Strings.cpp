#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

#define pb push_back
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define mp make_pair


ll power (int n)
{
	if (n == 0)
		return 1 ;
	if (n == 1)
		return 2 ;

	if (n % 2)
		return (2 * power (n - 1)) % MOD ;
	else
	{
		ll haf ;
		haf = power(n/2) ;
		return (haf * haf) % MOD ;
	}
}

int main ()
{
	int n ;

	cin >> n ;
	cout << power (n) << "\n" ;

	return 0 ;
}
