vector<int> Solution::solve(vector<int> &A) 
{
    int i, N = A.size() ;
    long long prod ;
    vector<int> ans (A) ;
    
    prod = 1 ;
    for (i = 0 ; i < N ; i++)
        prod *= A[i] ;
    
    for (i = 0 ; i < N ; i++)
        ans[i] = prod/ans[i] ;
        
    return ans ;
}

