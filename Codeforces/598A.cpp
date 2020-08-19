#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

typedef enum _nodestat
{
	UN, VISI, TED
} nodestat ;

#define MOD 1000000007

#define lli long long int
#define li long int
#define pii pair<int,int>
#define ppiipii pair<pair<int,int>,pair<int,int>>

#define vi vector<int>
#define vli vector<long int>
#define vlli vector<long long int>
#define vpii vector<pair<int,int>>

#define pb push_back
#define mp make_pair

#define um unordered_map
#define us unordered_set
#define miti map<int,int>


int main ()
{
	ios_base::sync_with_stdio (false) ;
	cin.tie (NULL) ;

	int t, expo ;
	lli n, s1, s2 ;
	cin >> t ;
	do
	{
		cin >> n ;
		if (n <= 4)
		{
			int ans ;
			switch (n)
			{
				case 1 : 
					ans = -1 ;
					break ;
				case 2 :
					ans = -3;
					break ;
				case 3 :
					ans = 0 ;
					break ;
				case 4 :
					ans = -4 ;
					break ;
			}
			cout << ans << "\n" ;
			continue ;
		}

		expo = log2 (n) ;
		s1 = (n*(n+1))/2 ;
		s2 = (lli)pow (2, expo+1) - 1 ;

		cout << s1 - 2*s2 << "\n" ;
	} while (--t) ;

	return 0 ;
}
