#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void eggdrop (int F, int E)
{
    if (E == 1)
    {
        cout << F << "\n" ;
        return ;
    }
    
    int f, e, x, min, maxegg ;
    vector<vector<int>> egg (F+1, vector<int> (E+1, -1)) ;
    
    egg[0][0] = 0 ;
    for (e = 1 ; e <= E ; e++)
    {
        egg[0][e] = 0 ;
        egg[1][e] = 1 ;
    }
    
    for (f = 0 ; f <= F ; f++)
        egg[f][1] = f ;
        
    for (f = 2 ; f <= F ; f++)
    {
        for (e = 2 ; e <= E ; e++)
        {
            min = INT_MAX ;
            for (x = 1 ; x < f ; x++)
            {
                maxegg = max (egg[x-1][e-1], egg[f-x][e]) ;
                if (maxegg < min)
                    min = maxegg ;
            }
            
            egg[f][e] = min + 1 ;
        }
    }
    
    cout << egg[F][E] << "\n" ;
    return ;
}

int main() 
{
    int noTest, E, F, i ;
    
    cin >> noTest ;
    for (i = 0 ; i < noTest ; i++)
    {
        cin >> E >> F ;
        eggdrop (F, E) ;
    }
    
	return 0;
}
