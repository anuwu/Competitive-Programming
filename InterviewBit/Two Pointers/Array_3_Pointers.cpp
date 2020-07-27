int intabs (int x)
{
    if (x < 0)
        return -x ;
    else
        return x ;
}

int getmin (int a, int b, int c)
{
    if (a < b)
    {
        if (a < c)
            return 0 ;
        return 2 ;
    }
    else
    {
        if (b < c)
            return 1 ;
        return 2 ;
    }
}


int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{
    int i, j, k, whichmin, minmax, maxdiff ;
    int N1 = A.size(), N2 = B.size(), N3 = C.size() ;

    minmax = INT_MAX ;
    i = j = k = 0 ;
    while (i<N1 && j<N2 && k<N3)
    {
        maxdiff = max (intabs (A[i] - B[j]), max (intabs(B[j] - C[k]), intabs(A[i] - C[k]))) ;
        if (maxdiff < minmax)
            minmax = maxdiff ;
            
        whichmin = getmin (A[i], B[j], C[k]) ;
        switch (whichmin)
        {
            case 0 :
                i++ ;
                break ;
            case 1 :
                j++ ;
                break ;
            case 2 :
                k++ ;
                break ;
        }
    }
    
    return minmax ;
}

