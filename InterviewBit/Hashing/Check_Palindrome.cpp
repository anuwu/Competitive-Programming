int Solution::solve(string A) 
{
    int i, nEven, nOdd ;
    bool palin ;
    unordered_map<char,int> m ;
    unordered_map<char,int>::iterator it ; 
    
    for (i = 0 ; i < A.length() ; i++)
    {
        if (m.find (A[i]) == m.end())
            m[A[i]] = 1 ;
        else
            m[A[i]]++ ;
    }
    
    nEven = nOdd = 0 ;
    for (it = m.begin() ; it != m.end() ; it++)
    {
        if (it->second % 2)
            nOdd++ ;
        else
            nEven++ ;
    }
    
    if (nOdd > 1)
        return false ;
        
    return true ;
}
