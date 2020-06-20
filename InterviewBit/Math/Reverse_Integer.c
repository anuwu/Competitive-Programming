#include <math.h> 
 
int reverse(int A) 
{
    int tmp, dig, rev = 0, oldrev ;
    if (A < 0)
        tmp = -A ;
    else
        tmp = A ;
    
    oldrev = rev ;
    while (tmp != 0)
    {
        dig = tmp % 10 ;
        rev = rev*10 + dig ;
        
        if (rev < 0)
        {
            while (tmp != 0)
            {
                dig = tmp % 10 ;
                if (dig != 0)
                    return 0 ;
                    
                tmp /= 10 ;
            }
            
            
            if (A < 0)
                return -oldrev ;
            else
                return oldrev ;
        }
        
        oldrev = rev ;
        tmp /= 10 ;
    }

    if (A < 0)
        return -rev ;
    else
        return rev ;
    
    printf ("Returning ") ;
    return 0 ;
}
