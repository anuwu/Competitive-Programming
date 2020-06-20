string Solution::solve(string A) 
{
    int i, nonspc = -1, spc = -1, spcFlag = 0, nonspcFlag = 0 ;
    
    string ans ("") ;
    string sub ;
    
    for (i = 0 ; A[i] != '\0' ; i++)
    {
        if (A[i] == ' ')
        {
            nonspcFlag = 0 ;
            if (spcFlag == 0)
            {
                spc = i ;
                spcFlag = 1 ;
                
                sub = A.substr (nonspc, spc - nonspc) ;
                ans.insert (0, sub) ;
                ans.insert (0, " ") ;
            }
        }
        else
        {
            spcFlag = 0 ;
            if (nonspcFlag == 0)
            {
                nonspc = i ;
                nonspcFlag = 1 ;
            }
        }
    }
    
    if (nonspc == -1)
        return ans ;
    if (spc < nonspc)
    {
        sub = A.substr (nonspc, i - nonspc) ;
        ans.insert (0, sub) ;
    }
    
    if (ans[0] == ' ')
        ans.erase (0 , 1) ;
    
    return ans ;
}
