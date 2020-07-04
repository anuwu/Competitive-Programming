
void retract (const string str, int* x)
{
    int cnt, i ;
    
    cnt = 0 ;
    i = *x ;
    do
    {
        do
        {
            cnt++ ;
            i -= 2 ;
        } while (i >= 0 && str[i] == 'B') ;
        
        while (cnt != 0 && i >= 0 && str[i] != 'B')
        {
            i-- ;
            cnt-- ;
        }
        
        if (i < 0)
        {
            *x = -1 ;
            return ;
        }
        else if (cnt == 0)
        {
            if (str[i] == 'B')
                continue ;
            else
                break ;
        }
    } while (true) ;
    
    *x = i ;
}

int Solution::solve(const string A, const string B) 
{
    int i, j, cmpA, cmpB, N1, N2 ;
    
    N1 = A.length () ;
    N2 = B.length () ;
    i = N1 - 1 ;
    j = N2 - 1 ;
    do
    {
        if (A[i] != 'B' && B[j] != 'B')
        {
            if (A[i] != B[j])
                return 0 ;
                
            i-- ;
            j-- ;
        }
        else
        {
            if (A[i] == 'B')
                retract (A, &i) ;
            if (B[j] == 'B')
                retract (B, &j) ;
        }
    } while (i >= 0 && j >= 0) ;
    
    if (i < 0 && j < 0)
        return 1 ;
    else
    {
        if (i >= 0)
        {
            if (A[i] == 'B')
            {
                retract (A, &i) ;
                if (i == -1)
                    return 1 ;
                else
                    return 0 ;
            }
            else
                return 0 ;
        }
        
        if (j >= 0)
        {
            if (B[j] == 'B')
            {
                retract (B, &j) ;
                if (j == -1)
                    return 1 ;
                else
                    return 0 ;
            }
            else
                return 0 ;
        }
    }
}

