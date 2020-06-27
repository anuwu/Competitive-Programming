// Working solution
int Solution::sqrt(int A) 
{
    if (A == 0)
        return 0 ;
    if (A <= 3)
        return 1 ;
    if (A < 9)
        return 2 ;
    if (A < 16)
        return 3 ;
        
        
    long long l, r, mid, cnt = 0, prod ;
    bool cond ;
    
    r = 2 ;
    prod = r*r ;
    while (prod > 0 && prod < A)
    {
        if (prod == A)
            return r ;
            
        cnt++ ;
        l = r ;
        r = 2*r ;
        prod = r*r ;
    }
    
    if (r > A/2)
        r = A/2 ;
    else
        
    while (l <= r)
    {
        cnt++ ;
        mid = (l + r)/2 ;
        prod = mid*mid ;
        if (prod == A)
            return mid ;
        else if (prod < A)
        {
            if (prod + 2*mid + 1 > A)
                return mid ;
 
            l = mid + 1 ;
        }
        else
        {
            if (prod - 2*mid + 1 < A)
                return mid - 1 ;
 
            r = mid - 1 ;
        }
    }
 
    return r ;
}


// Alternate solution
int Solution::sqrt(int A) 
{
    if (A == 0)
        return 0 ;
    if (A <= 3)
        return 1 ;
    if (A < 9)
        return 2 ;
    if (A < 16)
        return 3 ;
        
        
    int l, r, mid, cnt = 0, prod ;
    bool cond ;
    
    r = 2 ;
    prod = r*r ;
    while (prod > 0 && prod < A)
    {
        if (prod == A)
            return r ;
            
        cnt++ ;
        l = r ;
        r = 2*r ;
        prod = r*r ;
    }
    
    if (r > A/2)
        r = A/2 ;
        
    while (l <= r)
    {
        cnt++ ;
        mid = (l + r)/2 ;
        if (A/mid == mid)
            return mid ;
        else if (A/mid < mid)
            r = mid - 1 ;
        else
            l = mid + 1 ;
    }

    return r ;
}


