string Solution::findDigitsInBinary(int A) 
{
    string s("") ;
    int dig ;
    
    if (!A)
    {
        s.insert (0, "0") ;
        return s ;
    }   
    
    while (A != 0)
    {
        dig = A % 2 ;
        if (dig)
            s.insert (0, "1") ;
        else
            s.insert (0, "0") ;
            
        A /= 2 ;
    }
    
    return s ;
}
