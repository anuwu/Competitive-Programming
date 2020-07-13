int i, j, k ;

int merge (vector<int> &C, int low, int mid, int high)
{
    int i, j, k, inv ;
    vector<int> A (C.begin() + low, C.begin() + mid + 1) ;
    vector<int> B (C.begin() + mid + 1, C.begin() + high + 1) ;
    
    i = 0 ;
    j = 0 ;
    inv = 0 ;
    for (k = low ; i < A.size() && j < B.size() ; k++)
    {
        if (B[j] < A[i])
        {
            C[k] = B[j] ;
            
            inv += (A.size() - i) ;
            j++ ;
        }
        else
        {
            C[k] = A[i] ;
            i++ ;
        }
    }
    
    if (i == A.size ())
    {
        for ( ; j < B.size() ; j++, k++)
            C[k] = B[j] ;
    }
    
    if (j == B.size ())
    {
        for ( ; i < A.size() ; i++, k++)
            C[k] = A[i] ;
    }
    
    return inv ;
}

int mergeInversion (vector<int> &A, int low, int high)
{
    if (low >= high)
        return 0 ;
    
    int inv1, inv2, inv, mid ;
    
    mid = (low + high)/2 ;
    inv1 = mergeInversion (A, low, mid) ;       // 0, 1 --> [(0,0),(1,1)]
    inv2 = mergeInversion (A, mid + 1, high) ;  // 1, 1
    inv = inv1 + inv2 ;
    
    inv += merge (A, low, mid, high) ;
    
    return inv ;
}

int Solution::countInversions(vector<int> &A) 
{
   return mergeInversion (A, 0, A.size() - 1) ; 
}
