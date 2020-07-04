vector<int> Solution::nextPermutation(vector<int> &A) 
{
    if (A.size () == 0 || A.size () == 1)
        return A ;
    else if (A.size() == 2)
    {
        int tmp ;
        tmp = A[0] ;
        A[0] = A[1] ;
        A[1] = tmp ;
        
        return A ;
    }
    
    int i, ascbreak, tmp, breaknum, N ;
    
    ascbreak = -1 ;
    N = A.size() ;
    for (i = N-2 ; i >= 0 ; i--)
    {
        if (A[i] < A[i+1])
        {
            ascbreak = i+1 ;
            break ;
        }
    }
    
    if (ascbreak == -1)
    {
        sort (A.begin (), A.end ()) ;
        return A ;
    }
    else
    {
        for (breaknum = N-1 ; breaknum >= ascbreak ; breaknum--)
        {
            if (A[breaknum] > A[ascbreak - 1])
                break ;
        }
        
        tmp = A[breaknum] ;
        A[breaknum] = A[ascbreak - 1] ;
        A[ascbreak - 1] = tmp ;
    }
    
    sort (A.begin () + ascbreak, A.end()) ;
    return A ;
}

