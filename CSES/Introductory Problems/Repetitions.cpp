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
	int i, cnt, maxcnt, l ;
	string str ;

	cin >> str ;
	l = str.length() ;

	if (l <= 1)
	{
		cout << 1 << "\n" ;
		return 0 ;
	}

	maxcnt = INT_MIN ;
	cnt = 1 ;
	for (i = 1 ; i < l ; i++)
	{
		if (str[i] == str[i-1])
			cnt++ ;
		else
		{
			if (cnt > maxcnt)
				maxcnt = cnt ;
			cnt = 1 ;
		}
	}

	if (cnt > maxcnt)
		maxcnt = cnt ;

	cout << maxcnt << "\n" ;

	return 0 ;
}
