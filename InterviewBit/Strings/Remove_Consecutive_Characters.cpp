string Solution::solve(string A, int B) 
{
    if (B == 0)
        return A ;
    
    int i, j, len, cnt ;
    string ans ("") ;
    
    
    if (B == 1)
        return ans ;
     
    ans.reserve (A.length ()) ;
    len = A.length () ;  
    for (i = 0 ; i < len - 1 ; i++)
    {
        if (A[i+1] == A[i])
        {
            j = i+1 ;
            cnt = 1 ;
            do
            {
                cnt++ ;
                j++ ;
            } while (j < len && A[j] == A[i]) ;
            
            if (cnt != B)
                ans.append (A.substr (i, cnt)) ;
                
            i = j - 1 ;
        }
        else
            ans.append (A.substr (i, 1)) ;
    }
    
    if (j != len)
        ans.append (A.substr (len-1, 1)) ;
    
    return ans ;
}

