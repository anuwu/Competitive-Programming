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
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	int n ;
	li x ;
	set<li> s ;

	scanf ("%d", &n) ;
	do
	{
		scanf ("%ld", &x) ;
		s.insert (x) ;
	} while (--n) ;

	cout << (int)s.size() << "\n" ;

	return 0 ;
}
