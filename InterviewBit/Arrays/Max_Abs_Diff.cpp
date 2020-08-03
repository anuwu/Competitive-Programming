int Solution::maxArr(vector<int> &A) 
{
    if (!A.size())
        return 1 ;
    
    int i, min1, max1, min2, max2, N = A.size() ;
    
    min1 = min2 = INT_MAX ;
    max1 = max2 = INT_MIN ;
    
    for (i = 0 ; i < N ; i++)
    {
        min1 = min (min1, A[i] - i) ;
        max1 = max (max1, A[i] - i) ;
        
        min2 = min (min2, A[i] + i) ;
        max2 = max (max2, A[i] + i) ;
    }
    
    return max (max1 - min1, max2 - min2) ;
    
}

