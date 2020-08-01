queue<pair<int,int>> q ;
vector<vector<bool>> vis ;
vector<string> Cglob ;
 
 
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
 
void injectZeroes (pair<int,int> p)
{
    int i, j, n, ni, nj ;
    
    i = p.first ;
    j = p.second ;
    
    if (i+1 < vis.size() && Cglob[i][j] == 'D' && !vis[i+1][j])
    {
        vis[i+1][j] = true ;
        
        p.first = i+1 ;
        q.push (p) ;
        injectZeroes (p) ;
    }
    
    if (i-1 >= 0 && Cglob[i][j] == 'U' && !vis[i-1][j])
    {
        vis[i-1][j] = true ;
        
        p.first = i-1 ;
        q.push (p) ;
        injectZeroes (p) ;
    }
    
    p.first = i ;
    if (j+1 < vis[0].size() && Cglob[i][j] == 'R' && !vis[i][j+1])
    {
        vis[i][j+1] = true ;
        
        p.second = j+1 ;
        q.push (p) ;
        injectZeroes (p) ;
    }
    
    if (j-1 >= 0 && Cglob[i][j] == 'L' && !vis[i][j-1])
    {
        vis[i][j-1] = true ;
        
        p.second = j-1 ;
        q.push (p) ;
        injectZeroes (p) ;
    }
}
 
int Solution::solve(int A, int B, vector<string> &C) 
{
    q = queue<pair<int,int>> () ;
    vis.clear () ;
    Cglob = C ;
    
    int i, j, n, ni, nj, frontier, sz ;
    bool found ;
    vector<char> neighs ;
    pair<int,int> p ;
    vis = vector<vector<bool>> (A, vector<bool> (B, false)) ;
    
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
        
            injectZeroes (p) ;
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
