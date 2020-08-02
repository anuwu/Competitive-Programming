typedef enum _nodestat
{
    UN, VISI, TED
} nodestat ;

void getNeighs (int i, int j, vector<pair<int,int>> &neighs)
{
    neighs.clear () ;
    
    neighs.push_back (make_pair (i-1, j-1)) ;
    neighs.push_back (make_pair (i-1, j)) ;
    neighs.push_back (make_pair (i-1, j+1)) ;
    neighs.push_back (make_pair (i, j-1)) ;
    neighs.push_back (make_pair (i, j+1)) ;
    neighs.push_back (make_pair (i+1, j-1)) ;
    neighs.push_back (make_pair (i+1, j)) ;
    neighs.push_back (make_pair (i+1, j+1)) ;
}

void dfs (int i, int j, int &regCnt, vector<vector<nodestat>> &vis, vector<vector<int>> &A)
{
    if (i < 0 || i >= vis.size() || j < 0 || j >= vis[0].size())
        return ;
    
    if (!A[i][j])
    {
        vis[i][j] = TED ;
        return ;
    }
        
    if (vis[i][j] == VISI || vis[i][j] == TED)
        return ;
        
    regCnt = regCnt + 1 ;
    vis[i][j] = VISI ;
    
    vector<pair<int,int>> neighs ;
    getNeighs (i, j, neighs) ;
    
    for (int k = 0 ; k < neighs.size() ; k++)
        dfs (neighs[k].first, neighs[k].second, regCnt, vis, A) ;
    
    vis[i][j] = TED ;
}

int Solution::solve(vector<vector<int>> &A) 
{
    int i, j, regCnt, maxCnt, N = A.size(), M = A[0].size() ;
    vector<vector<nodestat>> vis (N, vector<nodestat> (M, UN)) ;
    
    maxCnt = INT_MIN ;
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; j < M ; j++)
        {
            if (!A[i][j])
                vis[i][j] = TED ;
            else
            {
                if (vis[i][j] == UN)
                {
                    regCnt = 0 ;
                    dfs (i, j, regCnt, vis, A) ;
                    if (regCnt > maxCnt)
                        maxCnt = regCnt ;
                }
            }
        }
    }
    
    if (maxCnt == INT_MIN)
        return 0 ;
    
    return maxCnt ;
}

