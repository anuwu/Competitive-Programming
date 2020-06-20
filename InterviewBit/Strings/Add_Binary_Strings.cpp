string Solution::addBinary(string A, string B) 
{
    if (A.size () == 0)
        return B ;
    else if (B.size () == 0)
        return A ;
    
    int i, j, c, a, b, s, Aflag = 1, Bflag = 1 ;
    char ch ;
    string ans ("") ;
    
    i = A.size () - 1 ;
    j = B.size () - 1 ;
    c = 0 ;
    while (i >= 0 && j >= 0)
    {
        a = (int)(A[i] - '0') ;
        b = (int)(B[j] - '0') ;
        
        s = a ^ (b ^ c) ;
        ch = s ? '1' : '0' ;
        ans.insert (0, string (1, ch)) ;
        
        c = (a & b) | (b & c) | (a & c) ;
        i-- ;
        j-- ;
    }
    
    // --------------------------------------------------------------------
    
    if (i < 0 && j < 0)
    {
        if (c)
            ans.insert (0, "1") ;
        return ans;
    }
    if (i < 0)
        Aflag = 0 ;
    if (j < 0)
        Bflag = 0 ;
    
    while (i >= 0 && c)
    {
        a = (int)(A[i] - '0') ;
        
        s = a ^ c ;
        ch = s ? '1' : '0' ;
        
        ans.insert (0, string (1, ch)) ;
        
        c = a & c ;
        i-- ;
    }
    if (i >= 0 && Aflag && !c)
    {
        ans.insert (0, A.substr(0, i + 1)) ;
        return ans ;
    }
    if (Aflag)
    {
        if (c)
            ans.insert (0, "1") ;
            
        return ans ;
    }
    
    // --------------------------------------------------------------------
    
    while (j >= 0)
    {
        b = (int)(B[j] - '0') ;
        
        s = b ^ c ;
        ch = s ? '1' : '0' ;
        
        ans.insert (0, string (1, ch)) ;
        
        c = b & c ;
        j-- ;
    }
    if (j >= 0 && Bflag && !c)
    {
        ans.insert (0, B.substr(0, j + 1)) ;
        return ans ;
    }
    
    if (Bflag)
    {
        if (c)
            ans.insert (0, "1") ;
            
        return ans ;
    }
}
