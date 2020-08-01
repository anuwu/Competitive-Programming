
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

int Solution::solve(int A, int B, vector<string> &C) 
{
    int i, j, n, edge, ni, nj ;
    vector<vector<int>> dist (A, vector<int> (B, INT_MAX)) ;
    vector<char> neighs ;
    set<pair<int,pair<int,int>>> s ;
    set<pair<int,pair<int,int>>>::iterator it ;
    pair<int,pair<int,int>> ps ;
    pair<int,int> p ;
    
    dist[0][0] = 0 ;
    s.insert (make_pair (0, make_pair (0, 0))) ;
    while (!s.empty ())
    {
        it = s.begin() ;
        p = it->second ;
        s.erase (it) ;
        
        getNeighbors (p, neighs, A, B) ;
        i = p.first ;
        j = p.second ;
        
        for (n = 0 ; n < neighs.size() ; n++)
        {
            neighIndex (i, j, neighs[n], &ni, &nj) ;
            edge = C[i][j] == neighs[n] ? 0 : 1 ;
            if (dist[i][j] + edge < dist[ni][nj])
            {
                ps = make_pair (dist[ni][nj], make_pair(ni, nj)) ;
                if (dist[ni][nj] != INT_MAX)
                    s.erase (s.find (ps)) ;
                    
                dist[ni][nj] = dist[i][j] + edge ;
                ps.first = dist[ni][nj] ;
                s.insert (ps) ;
            }
        }
    }
    
    return dist[A-1][B-1] ;
}

