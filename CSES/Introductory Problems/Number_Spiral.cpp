#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

#define pb push_back
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define mp make_pair

ll spiral (int r, int c)
{
	if (r == 1 && c == 1)
		return 1 ;

	int m ;
	m = max (r, c) ;
	ll lastsq, ans ;
	lastsq = (ll)(m - 1) * (m - 1) ;


	if (m % 2)
	{
		ans = lastsq + c ;
		if (c > r)
			ans += c - r ;
	}
	else
	{
		ans = lastsq + r ;
		if (r > c)
			ans += r - c; 
	}

	return ans ;
}

int main ()
{
	int i, t, x, y ;
	vector<ll> ans ;

	cin >> t ;
	do
	{
		cin >> y >> x ;
		ans.pb (spiral (y, x)) ;
	} while (--t) ;

	for (i = 0 ; i < (int)ans.size() ; i++)
		cout << ans[i] << "\n" ;

	return 0 ;
}
