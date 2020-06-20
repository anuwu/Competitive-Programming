int Solution::mice(vector<int> &A, vector<int> &B) 
{
    sort (A.begin(), A.end()) ;
    sort (B.begin(), B.end()) ;
    
    int i, max = 0, diff ;
    for (i = 0 ; i < A.size () ; i++)
    {
        diff = A[i] - B[i] ;
        diff = diff > 0 ? diff : -diff ;
        if (diff > max)
            max = diff ;
    }
    
    return max ;
}
