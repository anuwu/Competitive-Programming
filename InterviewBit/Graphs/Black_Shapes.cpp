typedef enum _nodestat
{
    UN, VISI, TED
} nodestat ;

void dfs (int i, int j, vector<string> &A, vector<vector<nodestat>> &vis)
{
    vis[i][j] = VISI ;
    
    int k, y, x ;
    vector<pair<int,int>> neigh ;
    neigh.push_back (make_pair (i+1, j)) ;
    neigh.push_back (make_pair (i, j+1)) ;
    neigh.push_back (make_pair (i-1, j)) ;
    neigh.push_back (make_pair (i, j-1)) ;
    
    for (k = 0 ; k < neigh.size() ; k++)
    {
        y = neigh[k].first ;
        x = neigh[k].second ;
        
        if (y < A.size() && x < A[0].length() && A[y][x] == 'X' && vis[y][x] == UN)
            dfs (y, x, A, vis) ;
    }
    
    vis[i][j] = TED ;
}


int Solution::black(vector<string> &A) 
{
    int i, j, shapes, N = A.size(), M = A[0].length() ;
    vector<vector<nodestat>> vis (N, vector<nodestat> (M, UN)) ;
    
    shapes = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; j < M ; j++)
        {
            if (A[i][j] == 'O')
                vis[i][j] = TED ;
            else if (A[i][j] == 'X' && vis[i][j] == UN)
            {
                dfs (i, j, A, vis) ;
                shapes++ ;
            }
        }
    }
    
    return shapes ;
}

