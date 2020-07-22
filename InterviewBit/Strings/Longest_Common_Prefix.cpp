string Solution::longestCommonPrefix(vector<string> &A) 
{
    int i, j, N = A.size() ;
    bool fin ;
    char ch ;
    string ans ("") ;
    
    j = -1 ;
    do
    {
        if (j + 1 >= A[0].length ())
            break ;
    
        ch = A[0][j+1] ;
        fin = true ;
        for (i = 1 ; i < N ; i++)
        {
            if (j+1 >= A[i].length () || A[i][j+1] != ch)
            {
                fin = false ;
                break ;
            }
        }
        
        if (!fin)
            break ;
        
        j++ ;
    } while (true) ;
    
    if (j != -1)
        ans = A[0].substr (0, j+1) ;
    
    return ans ;
}

