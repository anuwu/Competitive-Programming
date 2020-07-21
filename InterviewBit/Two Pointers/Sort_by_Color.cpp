void Solution::sortColors(vector<int> &A) 
{
    int cnt0, cnt1, cnt2, i, N = A.size () ;
    
    cnt0 = cnt1 = cnt2 = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] == 0)
            cnt0++ ;
        else if (A[i] == 1)
            cnt1++ ;
        else if (A[i] == 2)
            cnt2++ ;
    }
    
    i = 0 ;
    for (--cnt0 ; cnt0 >= 0 ; cnt0--)
        A[i] = 0 ;
        
    for (--cnt1 ; cnt1 >= 0 ; cnt1--)
        A[i] = 1 ;
        
    for (--cnt2 ; cnt2 >= 0 ; cnt2--)
        A[i] = 2 ;
}

