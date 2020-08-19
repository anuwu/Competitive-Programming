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
	int i, n ;

	cin >> n ;
	if (n == 1)
	{
		cout << 1 << "\n" ;
		return 0 ;
	}
	else if (n <= 3)
	{
		cout << "NO SOLUTION" << "\n" ;
		return 0 ;
	}
	else if (n == 4)
	{
		cout << "2 4 1 3" << "\n" ;
		return 0 ;
	}

	for (i = 1 ; i <= n ; i += 2)
		cout << i << " " ;

	for (i = 2 ; i <= n ; i += 2)
		cout << i << " " ;

	cout << "\n" ;

	return 0 ;
}
