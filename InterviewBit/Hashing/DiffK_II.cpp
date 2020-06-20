int Solution::diffPossible(const vector<int> &A, int B) 
{
    if (A.size () == 0) return 0 ;
    
    unordered_map<int,int> m ;
    int i ;
    m[A[0]] = 0 ;
    for (i = 1 ; i < A.size () ; i++)
    {
        if (m.find(B + A[i]) != m.end () || m.find)
    }
}
