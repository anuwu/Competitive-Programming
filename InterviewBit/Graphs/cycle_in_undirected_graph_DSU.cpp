int find (int x, vector<int> &ds)
{
    if (ds[x] == -1)
        return x ;
    else
        return find (ds[x], ds) ;
}

int Solution::solve(int A, vector<vector<int>> &B)
{
    int i, p1, p2, N = B.size() ;
    vector<int> ds (A+1, -1) ;
    
    for (i = 0 ; i < N ; i++)
    {
        p1 = find (B[i][0], ds) ;
        p2 = find (B[i][1], ds) ;
        
        if (p1 == p2)
            return 1 ;
            
        ds[p1] = p2 ;
    }
    
    return 0 ;
}
