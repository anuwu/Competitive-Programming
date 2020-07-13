int Solution::countMismatchedPayments(vector<string> &A, vector<int> &B, vector<string> &C, vector<int> &D) 
{
    int i, mismatch ;
    unordered_map<string,int> m ;
    for (i = 0 ; i < A.size() ; i++)
        m[A[i]] = B[i] ;
    
    mismatch = 0 ;
    for (i = 0 ; i < C.size() ; i++)
        if (m[C[i]] != D[i])
            mismatch++ ;
            
    return mismatch ;
}

