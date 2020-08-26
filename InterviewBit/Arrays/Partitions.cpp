int Solution::solve(int A, vector<int> &B) 
{
    if (A < 3)
        return 0 ;
    else if (A == 3 && B[0] == B[1] && B[1] == B[2])
        return 1 ;
    
    int i, j, cnt ;
    long long sum, end ;
    vector<long long> pf (A, 0) ;
    unordered_map<long long,int> m ;
    
    sum = 0 ;
    for (i = 0 ; i < A ; i++)
    {
        sum += B[i] ;
        pf[i] = sum ;
    }
    end = pf[A-1] ;
    
    cnt = 0 ;
    m[pf[0]] = 1 ;
    for (j = 1 ; j < A-1 ; j++)
    {
        if (pf[j] % 2 == 1 || m.find(pf[j]/2) == m.end() || 3*pf[j]/2 != end)
            ;
        else
            cnt += m[pf[j]/2] ;
            
        
        if (m.find (pf[j]) == m.end())
            m[pf[j]] = 1 ;
        else
            m[pf[j]]++ ;
    }
    
    return cnt ;
}