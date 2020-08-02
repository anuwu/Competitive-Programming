
int Solution::repeatedNumber(const vector<int> &A) 
{
    int cand1, cand2, cnt1, cnt2, i, N = A.size() ;
    
    cand1 = cand2 = INT_MAX ;
    cnt1 = cnt2 = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] == cand1)
            cnt1++ ;
        else if (A[i] == cand2)
            cnt2++ ;
        else if (!cnt1)
        {
            cand1 = A[i] ;
            cnt1 = 1 ;
        }
        else if (!cnt2)
        {
            cand2 = A[i] ;
            cnt2 = 1 ;
        }
        else
        {
            cnt1-- ;
            cnt2-- ;
        }
    }
    
    cnt1 = cnt2 = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] == cand1)
            cnt1++ ;
        else if (A[i] == cand2)
            cnt2++ ;
    }
    
    if (cnt1 > N/3)
        return cand1 ;
    
    if (cnt2 > N/3)
        return cand2 ;
        
    return -1 ;
}

