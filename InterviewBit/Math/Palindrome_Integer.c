int isPalindrome(int A) 
{
    int tmp = A, dig, rev = 0 ;
    
    while (tmp != 0)
    {
        dig = tmp % 10 ;
        rev = rev*10 + dig ;
        tmp /= 10 ;
    }
    
    while (A != 0)
    {
        if (A % 10 != rev % 10)
            return 0 ;
            
        A /= 10 ;
        rev /= 10 ;
    }
    
    return 1 ;
}
