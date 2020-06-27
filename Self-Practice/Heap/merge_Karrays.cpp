#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

vector<int> mergeKarrays (vector<vector<int>> &Klist)
{
	int i, K = Klist.size (), anslen = 0, listindex ; 
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq ;
	vector<int> indices, ans ;
	pair<int, int> min ;

	indices = vector<int> (K, 0) ;
	for (i = 0 ; i < K ; i++)
	{
		pq.push (make_pair (Klist[i][0], i)) ;
		anslen += Klist[i].size () ;
	}

	ans.reserve (anslen) ;
	while (!pq.empty ())
	{
		min = pq.top () ;
		ans.push_back (min.first) ;
		listindex = min.second ;
		indices[listindex]++ ;

		pq.pop () ;
		if (indices[listindex] < Klist[listindex].size ())
			pq.push (make_pair (Klist[listindex][indices[listindex]], listindex)) ;
	}

	return ans ;
}

int main ()
{
	int K, N, in, i, j ;
	vector<int> list, mergedList ;
	vector<vector<int>> Klist ;

	cin >> K ;
	for (i = 0 ; i < K ; i++)
	{
		cin >> N ;
		for (j = 0 ; j < N ; j++)
		{
			cin >> in ;
			list.push_back (in) ;
		}

		Klist.push_back (list) ;
		list.clear () ;
	}

	mergedList = mergeKarrays (Klist) ;
	for (i = 0 ; i < mergedList.size () ; i++)
		cout << mergedList[i] << " " ;

	cout << "\n" ;
	return 0 ;
}