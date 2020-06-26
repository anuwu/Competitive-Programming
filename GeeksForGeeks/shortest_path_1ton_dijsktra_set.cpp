#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void pathLength(int N)
{
    int minindex, neigh1, neigh2 ;
    vector<int> dist (N, INT_MAX) ; 
    set<pair<int,int>> vertSet ;
    pair<int, int> minvert ;            // <distance, vertex>
    
    dist[0] = 0 ;
    vertSet.insert (make_pair (0, 0)) ;
    while (!vertSet.empty ())
    {
        minvert = *(vertSet.begin ()) ;
        vertSet.erase (vertSet.begin ()) ;
        
        minindex = minvert.second ;
        neigh1 = minindex + 1 ;
        neigh2 = 3*(minindex + 1) - 1 ;
        
        if (neigh1 < N && dist[minindex] + 1 < dist[neigh1])
        {
            if (dist[neigh1] != INT_MAX)
                vertSet.erase (vertSet.find (make_pair (dist[neigh1], neigh1))) ;
                
            dist[neigh1] = dist[minindex] + 1 ;
            vertSet.insert (make_pair (dist[neigh1], neigh1)) ;
        }
        
        if (neigh2 < N && dist[minindex] + 1 < dist[neigh2])
        {
            if (dist[neigh2] != INT_MAX)
                vertSet.erase (vertSet.find (make_pair (dist[neigh2], neigh2))) ;
                
            dist[neigh2] = dist[minindex] + 1 ;
            vertSet.insert (make_pair (dist[neigh2], neigh2)) ;
        }
    }
    
    cout << dist[N - 1] << "\n" ;
}

int main() 
{
	int noTest, N, i ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N ;
	    pathLength (N) ;
	}
	
	return 0;
}