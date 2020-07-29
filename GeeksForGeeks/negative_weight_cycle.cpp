#include <stdio.h>
#include <bits/stdc++.h>

using namespace std ;


void negativeCycle (int V, vector<vector<int>> B)
{

    int i, j, E = B.size() ;
    vector<int> sp (V, INT_MAX) ;
    
    sp[0] = 0 ;
    for (i = 1 ; i < V ; i++)
    {
        for (j = 0 ; j < E ; j++)
            if (sp[B[j][0]] != INT_MAX && sp[B[j][0]] + B[j][2] < sp[B[j][1]])
                sp[B[j][1]] = sp[B[j][0]] + B[j][2] ;
    }
    
    for (i = 0 ; i < E ; i++)
    {
        if (sp[B[i][0]] + B[i][2] < sp[B[i][1]])
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
