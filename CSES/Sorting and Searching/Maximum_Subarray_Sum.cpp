#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

#define pb push_back
#define ll long long
#define li long int
#define MOD 1000000007
#define pii pair<int,int>
#define mp make_pair
#define um unordered_map
#define us unordered_set


int main ()
{
	ios_base::sync_with_stdio (false) ;
	cin.tie (NULL) ;

	int n, x ;
	li end, maxsum ;

	cin >> n ;
	cin >> maxsum ;
	end = maxsum ;
	--n ;

	while (n--)
	{
		cin >> x ;
		if (end < 0)
			end = x ;
		else
			end += x ;

		maxsum = max (maxsum, end) ;
	}

	cout << maxsum << "\n" ;

	return 0 ;
}
