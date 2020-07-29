int find (int x, vector<pair<int,int>> &ds)
{
    if (ds[x].first != x)
        ds[x].first = find (ds[x].first, ds) ;
        
    return ds[x].first ;
}

void dsUnion (int p1, int p2, vector<pair<int, int>> &ds)
{
    if (ds[p1].second < ds[p2].second)
        ds[p1].first = p2 ;
    else if (ds[p2].second < ds[p1].second)
        ds[p2].first = p1 ;
    else
    {
        ds[p1].first = p2 ;
        ds[p2].second++ ;
    }
}

int Solution::solve(int A, vector<vector<int>> &B)
{
    int i, p1, p2, N = B.size() ;
    vector<pair<int,int>> ds (A+1, make_pair (0, 0)) ;
    
    for (i = 1 ; i <= A ; i++)
        ds[i].first = i ;
    
    for (i = 0 ; i < N ; i++)
    {
        p1 = find (B[i][0], ds) ;
        p2 = find (B[i][1], ds) ;
        
        if (p1 == p2)
            return 1 ;
        
        dsUnion (p1, p2, ds) ;
    }
    
    return 0 ;
}