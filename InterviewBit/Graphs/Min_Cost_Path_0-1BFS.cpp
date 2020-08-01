void getNeighbors (pair<int,int> p, vector<char> &neighs, int A, int B)
{
    neighs.clear () ;
    
    int i, j ;
    i = p.first ;
    j = p.second ;
    
    if (i+1 < A)
        neighs.push_back ('D') ;
    if (j+1 < B)
        neighs.push_back ('R') ;
    if (i-1 >= 0)
        neighs.push_back ('U') ;
    if (j-1 >= 0)
        neighs.push_back ('L') ;
}

void neighIndex (int i, int j, char ch, int* ni, int *nj)
{
    if (ch == 'L')
        j-- ;
    else if (ch == 'R')
        j++ ; 
    else if (ch == 'D')
        i++ ;
    else
        i--;
        
    *ni = i ;
    *nj = j ;
}

int Solution::solve (int A, int B, vector<string> &C) 
{
    int i, j, n, ni, nj, frontier, sz, edge ;
    bool found ;
    vector<char> neighs ;
    deque <pair<int,int>> q ;
    pair<int,int> p ;
    vector<vector<int>> dist (A, vector<int> (B, INT_MAX)) ;
    
    found = false ;
    frontier = 0 ;
    dist[0][0] = 0 ;
    q.push_back (make_pair (0, 0)) ;
    while (!q.empty ())
    {
        p = q.front () ;
        q.pop_front () ;
        
        i = p.first ; j = p.second ;
        getNeighbors (p, neighs, A, B) ;
        
        for (n = 0 ; n < neighs.size() ; n++)
        {
            edge = C[i][j] == neighs[n] ? 0 : 1 ;
            neighIndex (i, j, neighs[n], &ni, &nj) ;
            
            if (dist[i][j] +  edge < dist[ni][nj])
            {
                dist[ni][nj] = dist[i][j] + edge ;
                
                p.first = ni ;
                p.second = nj ;
                if (edge == 0)
                    q.push_front (p);
                else
                    q.push_back (p) ;
            }
        }
    }
    
    return dist[A-1][B-1] ;
}
