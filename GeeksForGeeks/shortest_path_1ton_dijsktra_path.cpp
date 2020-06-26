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

void printPath (vector<int> pred, int end)
{
    int i, vertex ;
    vector<int> path ;
    
    vertex = end ;
    do
    {
        path.push_back (vertex + 1) ;
        vertex = pred[vertex] ;
    }  while (vertex != -1) ;
    
    cout << path[path.size() - 1] << " " ;
    for (i = path.size () - 2 ; i >= 0 ; i--)
        cout << "--> " << path[i] << " " ;
}

void pathLength (int N)
{
    int minvertex, neigh1, neigh2 ;
    vector<bool> visited (N, false) ;       // Set of indices
    vector<int> dist (N, INT_MAX) ;         // Number i will have index (i - 1), index i is number (i + 1)
    vector<int> pred (N, INT_MAX) ;
    
    pred[0] = -1 ;
    dist[0] = 0 ;
    minvertex = 0 ;
    do
    {
        visited[minvertex] = true ;
        neigh1 = minvertex + 1 ;
        neigh2 = 3 * (minvertex + 1) - 1 ;
        
        if (neigh1 < N && dist[minvertex] + 1 < dist[neigh1])
        {
            dist[neigh1] = dist[minvertex] + 1 ;
            pred[neigh1] = minvertex ;
        }
            
        if (neigh2 < N && dist[minvertex] + 1 < dist[neigh2])
        {
            dist[neigh2] = dist[minvertex] + 1 ;
            pred[neigh2] = minvertex ;
        }
            
        minvertex = getMinindex (dist, visited) ;
        if (minvertex == -1)
            break ;
    } while (true) ;
    
    cout << "The path length is " << dist[N - 1] << "\n" ;
    cout << "The path is - \n" ;
    printPath (pred, N - 1) ;
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