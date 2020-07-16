vector<int> Solution::solve(vector<int> &A) 
{
    int i, max, N = A.size() ;
    vector<int> ans ;
    
    max = A[N-1] ;
    ans.push_back (max) ;
    
    for (i = N-2 ; i >= 0 ; i--)
    {
        if (A[i] > max)
        {
            max = A[i] ;
            ans.push_back (max) ;
        }
    }
    
    
    return ans ;
}

