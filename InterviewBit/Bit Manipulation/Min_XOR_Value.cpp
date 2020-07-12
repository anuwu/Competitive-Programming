int Solution::findMinXor(vector<int> &A) 
{
    int i, min, xorr, N = A.size() ;
    
    sort (A.begin(), A.end()) ;
    min = INT_MAX ;
    for (i = 0 ; i < N - 1 ; i++)
    {
        xorr = A[i] ^ A[i+1] ;
        if (xorr < min)
            min = xorr ;
    }
    
    return min ;
}

