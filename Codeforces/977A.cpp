#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

#define MOD 1000000007

#define ll long long
#define li long int
#define pii pair<int,int>

#define vi vector<int>
#define vli vector<long>
#define vpii vector<pair<int,int>>

#define pb push_back
#define mp make_pair

#define um unordered_map
#define umii unordered_map<int,int>
#define umchi unordered_map<char,int>
#define umlii unordered_map<long,int>
#define umlili unordered_map<long,long>

#define us unordered_set
#define usi unordered_set<int>
#define usli unordered_set<long>
#define usch unordered_set<char>

#define mii map<int,int>
#define mchi map<char,int>
#define mlii map<long,int>
#define mlili map<long,long>
#define mpiii map<pair<int,int>,int>


int main ()
{
	ios_base::sync_with_stdio (false) ;
	cin.tie (NULL) ;

	li n ;
	int k ;

	cin >> n >> k ;
	do
	{
		if (n % 10)
			n-- ;
		else
			n /= 10 ;
	} while (--k) ;

	cout << n << "\n" ;

	return 0 ;
}
