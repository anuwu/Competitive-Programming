vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) 
{
    vector<int> ans ;
    int i, j, k, N1, N2, N ;

    N1 = A.size () ;
    N2 = B.size () ;
    N = N1 + N2 ;
    i = 0 ;
    j = 0 ;
    for (k = 0 ; i < N1 && j < N2 && k < N ; k++)
    {
        if (A[i] < B[j])
            i++ ;
        else
        {
            if (A[i] == B[j])
            {
                ans.push_back (B[j]) ;
                i++ ;
            }
                
            j++ ;
        }
    }
    
    return ans ;
}
