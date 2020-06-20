#include <cctype>

char getLeft (string A, int *left)
{
    int i = *left, sz = A.size () ;
    char ch ;
    
    while (i < sz && !(isdigit (A[i]) || isalpha (A[i])))
        i++ ;
        
    if (i == A.size ())
    {
        *left = i ;
        return 0 ;
    }
        
    *left = i + 1 ;
    
    ch = A[i] ;
    if (isdigit (ch))
        return ch ;
    else
        return tolower (ch) ;
}

char getRight (string A, int *right)
{
    int i = *right ;
    char ch ;
    
    while (i >= 0 && !(isdigit (A[i]) || isalpha (A[i])))
        i-- ;
        
    if (i == -1)
    {
        *right = i ;
        return 0 ;
    }
        
    *right = i - 1 ;
    
    ch = A[i] ;
    if (isdigit (ch))
        return ch ;
    else 
        return tolower (ch) ;
}


int Solution::isPalindrome(string A) 
{
    int left = 0, right = A.size () - 1 ;
    char lch = 0 , rch = 0 ;
    
    while (left < right)
    {
        lch = getLeft (A, &left) ;
        rch = getRight (A, &right) ;
        
        if (lch != rch)
            return 0 ;
    }
    
    return 1 ;
}