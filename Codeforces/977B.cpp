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
#define umsi unordered_map<string,int>

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

	int l, maxf, f ;
	string str, gram, maxgram ;
	umsi m ;

	cin >> l >> str ;
	maxf = INT_MIN ;
	for (int i = 0 ; i < l-1 ; i++)
	{
		gram = str.substr (i, 2) ;
		if (m.find (gram) == m.end())
			m[gram] = f = 1 ;
		else
			f = ++m[gram] ;

		if (f > maxf)
		{
			maxf = f ;
			maxgram = gram ;
		}
	}

	cout << maxgram << "\n" ;

	return 0 ;
}
