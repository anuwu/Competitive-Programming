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
#define umlliti unordered_map<long long int,int>
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

typedef enum _nodestat
{
	UN, VISI, TED
} nodestat ;

void dfs (lli node, int ind, map<lli,vector<nodestat>> &vis, vlli &topo)
{
	vis[node][ind] = VISI ;

	lli n1, n2 ;
	n1 = node % 3 == 0 ? (vis.find(node/3) != vis.end() ? node/3 : -1) : -1 ;
	n2 = vis.find(node*2) != vis.end() ? node*2 : -1 ;

	if (n1 != -1)
		for (int i = 0 ; i < (int)vis[n1].size() ; i++)
			if (vis[n1][i] == UN)
			{
				//cout << node << " Visiting " << n1 << "\n" ;
				dfs (n1, i, vis, topo) ;
			}

	if (n2 != -1)
		for (int i = 0 ; i < (int)vis[n2].size() ; i++)
			if (vis[n2][i] == UN)
			{
				//cout << node << " Visiting " << n2 << "\n" ;
				dfs (n2, i, vis, topo) ;
			}


	//cout << "\tDone with " << node << "\n" ;
	vis[node][ind] = TED ;
	topo.pb (node) ;
}

int main ()
{
	ios_base::sync_with_stdio (false) ;
	cin.tie (NULL) ;

	int ind, n, vecsz ;
	lli in ;

	cin >> n ;
	map<lli,vector<nodestat>> vis ;
	vlli topo ;
	vector<nodestat> emp ;

	for (int i = 0 ; i < n ; i++)
	{
		cin >> in ;
		if (vis.find (in) == vis.end())
		{
			emp.clear () ;
			emp.pb (UN) ;
			vis[in] = emp ;
		}
		else
			vis[in].pb (UN) ;
	}

	auto it = vis.begin() ;
	ind = 0 ;
	vecsz = it->second.size() ;
	do
	{
		//cout << "Top visiting " << it->first << "\n" ;
		dfs (it->first, ind, vis, topo) ;

		do
		{
			do ind++ ; while (ind < vecsz && it->second[ind] != UN) ;
			if (ind == vecsz)
			{
				it++ ;
				ind = -1 ;
				if (it != vis.end())
					vecsz = it->second.size() ;
				else
					break ;
			}
			else
				break ;
		}
		while (true) ;
	} while (it != vis.end()) ;

	for (int i = n-1 ; i >= 0 ; i--)
		cout << topo[i] << " " ;

	cout << "\n" ;
	return 0 ;
}
