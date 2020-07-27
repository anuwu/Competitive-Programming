vector<vector<int> > Solution::threeSum(vector<int> &A) 
{
    int i, l, r, N = A.size() ;
    long long  target, sum ;
    unordered_set <int> s, s1 ;
    
    vector<int> triplet ;
    vector<vector<int>> ans ;
    
    sort (A.begin(), A.end()) ;
    for (i = 0 ; i < N - 2 ; i++)
    {
        l = i+1 ;
        r = N-1 ;
        target = -((long long)A[i]) ;
        
        if (s.find (target) == s.end ())
            s.insert (target) ;
        else
            continue ;
        
        s1.clear () ;
        while (l < r)
        {
            sum = (long long)A[l] + (long long)A[r] ;
            if (sum == target && s1.find(A[l]) == s1.end())
            {
                triplet.push_back (A[i]) ;
                triplet.push_back (A[l]) ;
                triplet.push_back (A[r]) ;
                ans.push_back (triplet) ;
                triplet.clear () ;
                
                
                s1.insert (A[l]) ;
                l++ ;
            }
            else if (sum < target)
                l++ ;
            else
                r-- ;
        }
    }
    
    
    return ans ;
}
