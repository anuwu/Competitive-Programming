int Solution::maxProduct(const vector<int> &A)
{
    if (A.size () == 1)
        return A[0] ;
    
    int i, N = A.size() ;
    int maxend, minend, maxp, minp, tmp ;
    
    maxend = minend = maxp = minp = 0 ;
    if (A[0] > 0)
        maxend = maxp = A[0] ;
    else
        minend = minp = A[0] ;
    
    for (i = 1 ; i < N ; i++)
    {
        if (A[i] == 0)
            maxend = minend = 0 ;
        else if (A[i] > 0)
        {
            if (maxend == 0 && minend == 0)
                maxend = A[i] ;
            else if (maxend == 0 && minend != 0)
            {
                maxend = A[i] ;
                minend *= A[i] ;
            }
            else if (maxend != 0 && minend == 0)
                maxend *= A[i] ;
            else
            {
                maxend *= A[i] ;
                minend *= A[i] ;
            }
        }
        else
        {
            if (maxend == 0 && minend == 0)
                minend = A[i] ;
            else if (maxend == 0 && minend != 0)
            {
                maxend = minend * A[i] ;
                minend = A[i] ;
            }
            else if (maxend != 0 && minend == 0)
            {
                minend = maxend * A[i] ;
                maxend = 0 ;
            }
            else
            {
                tmp = minend ;
                minend = maxend * A[i] ;
                maxend = tmp * A[i] ;
            }
        }
        
        maxp = max (maxp, maxend) ;
        minp = min (minp, minend) ;
    }
    
    return maxp ;
}

