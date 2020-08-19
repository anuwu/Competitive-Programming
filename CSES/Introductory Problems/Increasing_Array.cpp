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
	int i, n, runmax ;
	ll turns ;
	vector<int> arr ;

	cin >> n ;
	arr = vector<int> (n, 0) ;
 	for (i = 0 ; i < n ; i++)
		cin >> arr[i] ;

	turns = 0 ;
	runmax = arr[0] ;
	for (i = 1 ; i < n ; i++)
	{
		if (arr[i] < runmax)
			turns += (runmax - arr[i]) ;
		else if (arr[i] > runmax)
			runmax = arr[i] ;
	}

	cout << turns << "\n" ;

	return 0 ;
}
