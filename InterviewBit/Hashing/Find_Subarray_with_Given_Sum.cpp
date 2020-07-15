vector<int> Solution::solve(vector<int> &A, int B) 
{
    int i, N = A.size() ;
    unordered_map<long long, int> m ;
    vector<int> ans ;
    
    long long sum = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        sum += A[i] ;
        if (sum == B)
        {
            ans = vector<int> (A.begin(), A.begin() + i + 1) ;
            break ;
        }
        
        if (m.find (sum - B) != m.end ())
        {
            ans = vector<int> (A.begin()+ m[sum - B] + 1, A.begin() + i + 1) ;
            break ;
        }
        
        if (m.find (sum) == m.end ())
            m[sum] = i ;
    }
    
    if (!ans.size())
        ans.push_back (-1) ;
    
    return ans ;
}

