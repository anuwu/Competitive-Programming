#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void floydWarshall (vector<vector<int>> &G)
{
    int i, j, k, V = G.size() ;
    
    for (k = 0 ; k < V ; k++)
    {
        for (i = 0 ; i < V ; i++)
        {
            if (i == k)
                continue ;
            
            for (j = 0 ; j < V ; j++)
            {
                if (j == k || i == j)
                    continue ;
                
                if (G[i][k] != INT_MAX && G[k][j] != INT_MAX && G[i][k] + G[k][j] < G[i][j])
                    G[i][j] = G[i][k] + G[k][j] ;
                
            }
        }
    }
    
    for (i = 0 ; i < V ; i++)
    {
        for (j = 0 ; j < V ; j++)
            cout << (G[i][j] == INT_MAX ? string ("INF") : to_string (G[i][j])) << " " ;
        cout << "\n" ;
    }
}

int main() 
{
	int noTest, V, in, i, j, k ;
	vector<vector<int>> G ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> V ;
	    G = vector<vector<int>> (V, vector<int> (V, INT_MAX)) ;
	    for (j = 0 ; j < V ; j++)
	    {
	        for (k = 0 ; k < V ; k++)
	        {
	            cin >> in ;
	            if (in <= 500)
	                G[j][k] = in ;
	        }
	    }
	    
	    floydWarshall (G) ;
	}
	
	return 0;
}
