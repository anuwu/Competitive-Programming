int Solution::solve(vector<int> &A, int B, int C) 
{
    int i, j, sum, cnt, N = A.size() ;
    unordered_map<int,vector<int>> m ;
    vector<int> indices ;
    
    cnt = 0 ;
    sum = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] == B)
            A[i] = 1 ;
        else if (A[i] == C)
            A[i] = -1 ;
        else
            A[i] = 0 ;
            
        sum += A[i] ;
        if (sum == 0)
            cnt++ ;
            
        if (m.find (sum) == m.end ())
        {
            indices.clear () ;
            m[sum] = indices ;
        }
        else
            cnt += m[sum].size() ;
        
        m[sum].push_back (i) ;
    }
    
    return cnt ;
}

