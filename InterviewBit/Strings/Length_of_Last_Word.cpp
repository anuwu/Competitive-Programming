int Solution::lengthOfLastWord(const string A) {
    if (A[0] == '\0')
        return 0 ;
    
    int nonsp = -1, sp = -1, nonspFlag = 0, spFlag = 0 ;
    int i ;
    
    for (i = 0 ; A[i] != '\0' ; i++)
    {
        if (A[i] != ' ')
        {
            spFlag = 0 ;
            if (nonspFlag == 0)
            {
                nonsp = i ;
                nonspFlag = 1 ;
            }
        }
        else
        {
            nonspFlag = 0 ;
            if (spFlag == 0)
            {
                sp = i ;
                spFlag = 1 ;
            }
        }
    }
    
    if (nonsp == -1)
        return 0 ;
    
    if (sp < nonsp)
        return i - nonsp ;
    else
        return sp - nonsp ;
}
