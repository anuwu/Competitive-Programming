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

	int i, n ;
	li x, sum, diff ;
	map<li,int> m ;

	cin >> n >> sum ;
	i = 1 ;
	do
	{
		cin >> x ;
		diff = sum - x ;
		if (m.find (diff) != m.end())
		{
			printf ("%d %d\n", m[diff], i) ;
			return 0 ;
		} 

		m[x] = i ;
		i++ ;
	} while (--n) ;

	cout << "IMPOSSIBLE\n" ;

	return 0 ;
}
