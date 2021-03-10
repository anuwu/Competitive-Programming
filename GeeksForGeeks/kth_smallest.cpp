int partition (int A[], int l, int r)
{
    int ret, piv, lt, rt, tmp, rnd ;
    
    rnd = l + rand() % (r - l + 1) ;
    tmp = A[rnd] ;
    A[rnd] = A[l] ;
    A[l] = tmp ;

    piv = A[l] ;
    lt = l+1 ;
    rt = lt ;
    while (rt <= r)
    {
        if (A[rt] <= piv)
        {
            tmp = A[lt] ;
            A[lt] = A[rt] ;
            A[rt] = tmp ;
            lt++ ;
        }
        
        rt++ ;
    }
    
    ret = lt - 1 ;
    if (l != ret)
    {
        tmp = A[l] ;
        A[l] = A[ret] ;
        A[ret] = tmp ;
    }

    return ret ;
}

int kthSmallest(int A[], int l, int r, int k) 
{
    int piv = partition (A, l, r) ;
    
    if (piv - l + 1 == k)
        return A[piv] ;
    else if (piv - l + 1 > k)
        return kthSmallest(A, l, piv-1, k) ;
    else
        return kthSmallest(A, piv+1, r, k - (piv - l + 1)) ;
}
