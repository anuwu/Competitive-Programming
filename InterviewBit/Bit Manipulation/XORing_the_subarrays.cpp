int Solution::solve(vector<int> &A) 
{
    if (A.size () == 1)
        return A[0] ;
    
    int i, xorsum, ans, pairxor, endxor, N = A.size() ;
    
    ans = 0 ;
    xorsum = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        xorsum ^= A[i] ;
        ans ^= xorsum ;
        A[i] = xorsum ;
    }
    
    pairxor = A[0] ^ A[1] ;
    endxor = pairxor ;
    for (i = 2 ; i < N ; i++)
    {
        pairxor ^= (i % 2 ? endxor ^ A[i] : endxor) ;
        endxor ^= A[i] ;
    }
    
    ans ^= pairxor ;
    return ans ;
}

