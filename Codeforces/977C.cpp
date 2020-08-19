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

	int n, k ;
	cin >> n >> k ;
	vi arr (n ,0) ;

	for (int i = 0 ; i < n ; i++)
		cin >> arr[i] ;

	sort (arr.begin(), arr.end()) ;

	
	if (k == 0)
	{
		if (arr[0] == 1)
			cout << -1 << "\n" ;
		else
			cout << arr[0] - 1 << "\n" ;

		return 0 ;
	}


	k-- ;
	if (k == n-1 || arr[k] != arr[k+1])
		cout << arr[k] << "\n" ;
	else
		cout << -1 << "\n" ;


	return 0 ;
}
