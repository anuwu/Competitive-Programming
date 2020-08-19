#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

#define MOD 1000000007

#define ll long long
#define li long int
#define pii pair<int,int>
#define ppiipii pair<pair<int,int>,pair<int,int>>

#define vi vector<int>
#define vli vector<long>
#define vpii vector<pair<int,int>>

#define pb push_back
#define mp make_pair

#define um unordered_map
#define umiti unordered_map<int,int>
#define umchti unordered_map<char,int>
#define umliti unordered_map<long,int>
#define umlitli unordered_map<long,long>
#define umsti unordered_map<string,int>

#define us unordered_set
#define usi unordered_set<int>
#define usli unordered_set<long>
#define usch unordered_set<char>

#define miti map<int,int>
#define mchti map<char,int>
#define mliti map<long,int>
#define mlitli map<long,long>
#define mpiiti map<pair<int,int>,int>
#define mppiiiti map<pair<pair<int,int>,int>,int>
#define mppiitpii map<pair<int,int>,pair<int,int>>

#define spii set<pair<int,int>>
#define sppiii set<pair<pair<int,int>,int>>
#define sppiipii set<pair<pair<int,int>,pair<int,int>>>


int main ()
{
	ios_base::sync_with_stdio (false) ;
	cin.tie (NULL) ;

	int n, w, ans ;
	li maxsum, minsum, sum ;
	cin >> n >> w ;
	vi arr (n, 0) ;

	for (int i = 0 ; i < n ; i++)
		cin >> arr[i] ;

	maxsum = minsum = sum = arr[0] ;
	for (int i = 1 ; i < n ; i++)
	{
		sum += (li)arr[i] ;
		if (sum > maxsum)
			maxsum = sum ;
		else if (sum < minsum)
			minsum = sum ;
	}

	if (minsum < 0)
	{
		if (-minsum > w)
		{
			cout << 0 << "\n" ;
			return 0 ;
		}

		if (maxsum > 0)
		{
			ans = w - maxsum ;
			ans += minsum ;
			if (ans >= 0)
				cout << ans + 1 << "\n" ;
			else
				cout << 0 << "\n" ;
		}
		else
		{
			ans = w + minsum ;
			cout << ans + 1 << "\n" ;
		}
	}
	else
	{
		ans = w - maxsum ;
		if (ans >= 0)
			cout << ans + 1 << "\n" ;
		else
			cout << 0 << "\n" ;
	}
	
	return 0 ;
}
