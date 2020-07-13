int Solution::solve (string A) 
{
    if (!A.compare ("8") || !A.compare ("0"))
        return 1 ;
    
    int i, len, carry, dvdnd, quodig, rep ;
    char ch ;
    string num (A) ;
    
    
    len = num.length () ;

    if (len == 1 && num[0] != '8')
	    return 0 ;
    
    if (num[0] < '8')
        carry = (int)(num[0] - '0') ;
    else
        carry = num[0] - '8' ;
    
    for (i = 1 ; i < len - 1 ; i++)
    {
        if (carry)
        {
            dvdnd = carry*10 + (int)(num[i] - '0') ;
            quodig = dvdnd/8 ;
            carry = dvdnd % 8 ;
        }
        else
        {
            if (num[i] < '8')
                carry = (int)(num[i] - '0') ;
            else
                carry = num[i] - '8' ;
        }
    }
    
    if (carry)
    {
        dvdnd = carry*10 + (int)(num[i] - '0') ;
        quodig = dvdnd/8 ;
        carry = dvdnd % 8 ;
        if (carry)
            return 0 ;
    }
    else
    {
        if (num[i] != '8' && num[i] != '0')
            return 0 ;
    }
    
    return 1 ;
}
