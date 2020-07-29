
void orderPrimes (int A, int B, int C, int *p1, int *p2, int *p3)
{
    if (A <= B)
    {
        if (B <= C)
        {
            *p1 = A ;
            *p2 = B ;
            *p3 = C ;
        }
        else if (A <= C)
        {
            *p1 = A ;
            *p2 = C ;
            *p3 = B ;
        }
        else
        {
            *p1 = C ;
            *p2 = A ;
            *p3 = B ;
        }
    }
    else
    {
        if (A <= C)
        {
            *p1 = B ;
            *p2 = A ;
            *p3 = C ;
        }
        else if (B <= C)
        {
            *p1 = B ;
            *p2 = C ;
            *p3 = A ;
        }
        else
        {
            *p1 = C ;
            *p2 = B ;
            *p3 = A ;
        }
    }
}


vector<int> Solution::solve(int A, int B, int C, int D) 
{
    int i, i1, i2, i3, n1, n2, n3, p1, p2, p3 ;
    vector<int> ans (D+1, 0) ;
    
    if (D == 0)
        return vector<int> () ;

    orderPrimes (A, B, C, &p1, &p2, &p3) ;
    i1 = i2 = i3 = 0 ;
    ans[0] = 1 ;
    n1 = p1 ;
    n2 = p2 ;
    n3 = p3 ;
    
    for (i = 1 ; i <= D ; i++)
    {
        ans[i] = min (n1, min (n2, n3)) ;
        
        if (ans[i] == n1)
        {
            i1++ ;
            n1 = ans[i1]*p1 ;
        }
        if (ans[i] == n2)
        {
            i2++ ;
            n2 = ans[i2]*p2 ;
        }
        if (ans[i] == n3)
        {
            i3++ ;
            n3 = ans[i3]*p3 ;
        }
    }
    
    ans.erase (ans.begin()) ;
    return ans ;
}

