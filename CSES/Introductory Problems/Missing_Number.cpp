#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

#define pb push_back
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define mp make_pair


int main ()
{
	int i, n, in, x ;
	cin >> n ;

	x = 0 ;
	for (i = 1 ; i < n ; i++)
	{
		x ^= i ;
		cin >> in ;
		x ^= in ;
	}
	x ^= n ;
	cout << x << "\n" ;

	return 0 ;
}
