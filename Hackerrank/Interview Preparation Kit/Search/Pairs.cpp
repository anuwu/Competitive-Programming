int pairs(int k, vector<int> A) 
{
    int i, cnt, N = A.size() ;
    unordered_map<int,int> m ;

    cnt = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        if (m.find (A[i] + k) != m.end())
            cnt += m[A[i] + k] ;
        if (m.find (A[i] - k) != m.end())
            cnt += m[A[i] - k] ;

        if (m.find (A[i]) == m.end())
            m[A[i]] = 1 ;
        else
            m[A[i]]++ ;
    }

    return cnt ;
}
