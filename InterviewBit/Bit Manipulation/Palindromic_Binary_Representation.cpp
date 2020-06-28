int Solution::solve(int A) 
{
    if (A == 1)
        return 1 ;
    if (A == 2)
        return 3 ; 
    
    int minCtr, maxCtr, latLength, powmin, ctrVal, torev, rev, ans, i ;
    
    maxCtr = ceil (log(A+2)/log(2) - 2) ;
    minCtr = maxCtr - 1 ;
    
    powmin = pow(2, minCtr + 2) - 2 ;
    if (A > powmin + pow(2, maxCtr))
    {
        //Even length
        latLength = maxCtr + 1 ;
        ctrVal = (1 << maxCtr) + (A - powmin - pow(2, maxCtr) - 1) ;
        torev = ctrVal ;
    }
    else
    {
        // Odd length
        latLength = maxCtr ;
        ctrVal = (1 << maxCtr) + (A - powmin - 1) ; ;
        torev = ctrVal >> 1 ;
    }
    
    rev = 0 ;
    i = 0 ;
    while (torev != 0)
    {
        rev += torev % 2 ? (torev % 2) * pow(2, latLength - i - 1): 0 ;
        torev /= 2 ;
        i++ ;
    }
    
    ans = ctrVal << latLength ;
    ans += rev; 
        

    return ans ;
}
