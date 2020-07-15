int Solution::solve(vector<int> &A) 
{
    int i, N = A.size() ;
    unordered_set<long long> s ;
    long long sum ;
    
    sum = A[0] ;
    if (sum == 0)
        return 1 ;
    else
        s.insert (A[0]) ;
        
    for (i = 1 ; i < N ; i++)
    {
        sum += A[i] ;
        
        if (sum == 0 || s.find (sum) != s.end ())
            return 1 ;
            
        s.insert (sum) ;
    }
    
    return 0 ;
}


