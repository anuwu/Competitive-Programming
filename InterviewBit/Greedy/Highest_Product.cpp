int Solution::maxp3(vector<int> &A) 
{
    int i, prod1, prod2, sz ;
    
    sort (A.begin(), A.end()) ;
    sz = A.size () ;
    if (sz <= 3)
    {
        prod1 = 1 ;
        for (i = 0 ; i < sz ; i++)
            prod1 *= A[i] ;
            
        return prod1 ;
    }
    
    prod1 = (A[0] < 0 && A[1] < 0) ? A[0]*A[1]*A[sz - 1] : 0 ;
    prod2 = A[sz-1] * A[sz-2] * A[sz-3] ;
    
    if (prod2 > prod1) return prod2 ;
    else return prod1 ;
}
