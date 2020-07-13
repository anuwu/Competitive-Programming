string Solution::solve(string A, string B) 
{
    if (A.length () > B.length ())
        return "NO" ;
        
    int i, j, l1 = A.length(), l2 = B.length() ;
    
    i = 0 ;
    j = 0 ;
    while (j < l2)
    {
        while (j < l2 && A[i] != B[j])
            j++ ;
        
        if (j < l2)
            i++ ;
        
        if (i == l1)
            break ;
    }
    
    if (i == l1)
        return "YES" ;
    else
        return "NO" ;
}

