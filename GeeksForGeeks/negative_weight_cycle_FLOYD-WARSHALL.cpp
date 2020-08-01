#include <stdio.h>
#include <bits/stdc++.h>

using namespace std ;


void negativeCycle (int V, vector<vector<int>> B)
{
    int i, j, k, E = B.size() ;
    vector<vector<int>> G (V, vector<int> (V, INT_MAX)) ;
    
    for (i = 0 ; i < V ; i++)
        G[i][i] = 0 ;
        
    for (i = 0 ; i < E ; i++)
        G[B[i][0]][B[i][1]] = B[i][2] ;
        
    for (k = 0 ; k < V ; k++)
    {
        for (i = 0 ; i < V ; i++)
        {
            if (i == k)
                continue ;
                
            for (j = 0 ; j < V ; j++)
            {
                if (j == k)
                    continue ;
                    
                if (G[i][k] != INT_MAX && G[k][j] != INT_MAX && G[i][k] + G[k][j] < G[i][j])
                    G[i][j] = G[i][k] + G[k][j] ;
            }
        }
    }
    

    for (i = 0 ; i < V ; i++)
    {
        if (G[i][i] < 0)
        {
            cout << 1 << "\n" ;
            return ;
        }
    }
    
    cout << 0 << "\n" ;
}


int main() 
{
	int noTest, V, E, u, v, w, i, j ;
	vector<vector<int>> tc ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> V >> E ;
	    tc = vector<vector<int>> (E, vector<int> (3, 0)) ;
	    
	    for (j = 0 ; j < E ; j++)
	    {
	        cin >> u >> v >> w ;
	        tc[j][0] = u ;
	        tc[j][1] = v ;
	        tc[j][2] = w ;
	    }
	    
	    negativeCycle (V, tc) ;
	}
	
	return 0;
}
