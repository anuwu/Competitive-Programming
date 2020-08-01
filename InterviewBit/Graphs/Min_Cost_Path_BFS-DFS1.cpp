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

void injectZeroes (pair<int,int> p, queue<pair<int,int>> &q, vector<string> &C, vector<vector<bool>> &vis)
{
    int i, j, n, ni, nj ;
    vector<char> neighs ;
    getNeighbors (p, neighs, vis.size(), vis[0].size()) ;
    
    i = p.first ;
    j = p.second ;
    for (n = 0 ; n < neighs.size() ; n++)
    {
        if (neighs[n] == C[p.first][p.second])
        {
            neighIndex (i, j, neighs[n], &ni, &nj) ;
            if (!vis[ni][nj])
            {
                p.first = ni ;
                p.second = nj ;
                
                vis[ni][nj] = true ;
                q.push (p) ;
                injectZeroes (p, q, C, vis) ;
            }
        }
            
    }
}

int Solution::solve (int A, int B, vector<string> &C) 
{
    int i, j, n, ni, nj, frontier, sz ;
    bool found ;
    vector<char> neighs ;
    queue<pair<int,int>> q ;
    pair<int,int> p ;
    vector<vector<bool>> vis (A, vector<bool> (B, false)) ;
    
    found = false ;
    frontier = 0 ;
    q.push (make_pair (0, 0)) ;
    vis[0][0] = true ;
    while (!q.empty ())
    {
        sz = q.size() ;
        while (sz--)
        {
            p = q.front () ;
            q.pop () ;
            injectZeroes (p, q, C, vis) ;
            
            q.push (p) ;
        }
        
        sz = q.size() ;
        while (sz--)
        {
            p = q.front () ;
            q.pop () ;
            
            i = p.first ;
            j = p.second ;
            
            if (i == A-1 && j == B-1)
            {
                found = true ;
                break ;
            }
            
            getNeighbors (p, neighs, A, B) ;
            for (n = 0 ; n < neighs.size() ; n++)
            {
                neighIndex (i, j, neighs[n], &ni, &nj) ;
                p.first = ni ;
                p.second = nj ;
                
                if (!vis[ni][nj])
                {
                    vis[ni][nj] = true ;
                    q.push (p) ;
                }
            }
        }
        
        if (found)
            break ;
        
        frontier++ ;
    }
    
    return frontier ;
}
