vector<int> Solution::solve(vector<int> &A, int B) 
{
    int i, N ;
    vector<int> ans ;
    priority_queue<int> pq ;
    
    N = A.size () ;
    for (i = 0 ; i < N ; i++)
        pq.push (A[i]) ;
    
    for (i = 0 ; i < B ; i++)
    {
        ans.push_back (pq.top ()) ;
        pq.pop () ;
    }
    
    return ans ;
}
