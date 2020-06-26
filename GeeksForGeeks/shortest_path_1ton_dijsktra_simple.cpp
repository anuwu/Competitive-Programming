#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getMinindex (vector<int> &dist, vector<bool> &visited)
{
    int i, min, minindex ;
    
    min = INT_MAX ;
    minindex = -1 ;
    for (i = 0 ; i < dist.size () ; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i] ;
            minindex = i ;
        }
    }
    
    return minindex ;
}

void pathLength (int N)
{
    int minvertex, neigh1, neigh2 ;
    vector<bool> visited (N, false) ;       // Set of indices
    vector<int> dist (N, INT_MAX) ;         // Number i will have index (i - 1), index i is number (i + 1)
    
    dist[0] = 0 ;
    minvertex = 0 ;
    do
    {
        visited[minvertex] = true ;
        neigh1 = minvertex + 1 ;
        neigh2 = 3 * (minvertex + 1) - 1 ;
        
        if (neigh1 < N && dist[minvertex] + 1 < dist[neigh1])
            dist[neigh1] = dist[minvertex] + 1 ;
            
        if (neigh2 < N && dist[minvertex] + 1 < dist[neigh2])
            dist[neigh2] = dist[minvertex] + 1 ;
            
        minvertex = getMinindex (dist, visited) ;
        if (minvertex == -1)
            break ;
    } while (true) ;
    
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
