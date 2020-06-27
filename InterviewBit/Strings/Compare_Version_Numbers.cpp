int strCmpr (string A, string B)
{
    int i, lenA, lenB ;
    
    i = 0 ;
    while (i < A.length () && A[i] == '0')
        i++ ;
    A.erase (0, i) ;
    
    i = 0 ;
    while (i < B.length () && B[i] == '0')
        i++ ;
    B.erase (0, i) ;
    
    lenA = A.length () ;
    lenB = B.length () ;
    if (!lenA && !lenB)
        return 0 ;
    else if (lenA && !lenB)
        return 1 ;
    else if (!lenA && lenB)
        return -1 ;
    else if (lenA > lenB)
        return 1 ;
    else if (lenA < lenB)
        return -1 ;
        
    for (i = 0 ; i < lenA ; i++)
    {
        if (A[i] > B[i])
            return 1 ;
        else if (A[i] < B[i])
            return -1 ;
    }
    
    return 0 ;
}

int retZero (string s)
{
    int i ;
    
    for (i = 0 ; i < s.length () ; i++)
    {
        if (s[i] != '0' && s[i] != '.')
            return 1 ;
    }
    
    return 0 ;
}

int Solution::compareVersion(string A, string B) 
{
    int ai, aj, bi, bj, lenA, lenB, cmp ;
    
    lenA = A.length () ;
    lenB = B.length () ;
    ai = 0 ; aj = 1 ;
    bi = 0 ; bj = 1 ;
    do
    {
        while (aj < lenA && A[aj] != '.')
            aj++ ;
            
        while (bj < lenB && B[bj] != '.')
            bj++ ;
            
        if (ai < lenA && bi < lenB)
        {
            cmp = strCmpr (A.substr (ai, aj - ai), B.substr (bi, bj - bi)) ;
            
            if (cmp != 0)
                return cmp ;
            
            ai = aj + 1 ; aj = ai + 1 ;
            bi = bj + 1 ; bj = bi + 1 ;
        }
        else if (ai > lenA && bi < lenB)
            return -retZero (B.substr (bi, B.length() - bi)) ;
        else if (ai < lenA && bi > lenB)
            return retZero (A.substr (ai, A.length() - ai)) ;
        else
            break ;
    } while (true) ;
    
    return 0 ;
}

