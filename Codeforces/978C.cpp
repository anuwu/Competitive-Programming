#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

#define MOD 1000000007

#define lli long long int
#define li long int
#define pii pair<int,int>
#define ppiipii pair<pair<int,int>,pair<int,int>>

#define vi vector<int>
#define vli vector<long>
#define vlli vector<long long int>
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

	int dorms, ltrs ;
	lli no, sum ;

	cin >> dorms >> ltrs ;
	vlli rooms (dorms, 0) ;

	sum = 0 ;
	for (int i = 0 ; i < dorms ; i++)
	{
		cin >> rooms[i] ;
		sum += rooms[i] ;
		rooms[i] = sum ;
	}

	for (int i = 0 ; i < ltrs ; i++)
	{
		cin >> no ;

		if (no <= rooms[0])
		{
			cout << 1 << " " << no << "\n" ;
			continue ;
		}

		int lo, hi, mid, ans ;
		lo = 0 ;
		hi = dorms-1 ;
		while (lo <= hi)
		{
			mid = lo + (hi - lo)/2 ;
			if (rooms[mid] == no)
			{
				ans = mid ;
				break ;
			}
			else if (rooms[mid] < no)
			{
				ans = mid ;
				lo = mid + 1 ;
			}
			else
				hi = mid - 1 ;
		}

		if (rooms[ans] == no)
			cout << ans+1 << " " << rooms[ans] - rooms[ans-1] << "\n" ;
		else
			cout << ans+2 << " " << no - rooms[ans] << "\n" ;
	}

	return 0 ;
}
