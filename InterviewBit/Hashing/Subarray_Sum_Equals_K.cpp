int Solution::solve(vector<int> &A, int B) 
{
    int i, cnt, N = A.size() ;
    long long sum ;
    unordered_map<long long, int> m ;
    
    cnt = 0 ;
    sum = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        sum += A[i] ;
        if (sum == B)
            cnt++ ;
        
        if (m.find (sum - B) != m.end ())
            cnt += m[sum - B] ;
        
        if (m.find (sum) == m.end ())
            m[sum] = 1 ;
        else
            m[sum]++ ;
    }

    return cnt ;
}

