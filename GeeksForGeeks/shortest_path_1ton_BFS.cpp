#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void pathLength (int N)
{
    int level, node, levsize ;
    bool found = false ;
    queue<int> q ;
    vector<bool> vis (N+1, false) ;
    
    q.push (1) ;
    level = 0 ;
    while (!q.empty ())
    {
        levsize = q.size() ;
        while (levsize--)
        {
            node = q.front () ;
            q.pop () ;
            vis[node] = true ;
            if (node == N)
            {
                found = true ;
                break ;
            }
                
            if (3*node <= N && !vis[3*node])
                q.push (3*node) ;
                
            if (node+1 <= N && !vis[node+1])
                q.push (node+1) ;
        }
        
        if (found)
            break ;

        level++ ;
    }
    
    cout << level << "\n" ;
}

int main() 
{
	int noTest, N ;
	
	cin >> noTest ;
	while (noTest--)
	{
	    cin >> N ;
	    pathLength (N) ;
	}
	
	return 0;
}
