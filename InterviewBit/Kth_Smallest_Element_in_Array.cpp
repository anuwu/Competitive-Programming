int Solution::kthsmallest(const vector<int> &A, int B) 
{
    int min, max, i, low, high, mid, countLess, countEq ;
    
    min = max = A[0] ;
    for (i = 1 ; i < A.size() ; i++)
    {
        if (A[i] < min)
            min = A[i] ;
        if (A[i] > max)
            max = A[i] ;
    }
    

    low = min ;
    high = max ;
    while (low <= high)
    {
        mid = (low + high)/2 ;
        countLess = countEq = 0 ;
        for (i = 0 ; i < A.size () ; i++)
        {
            if (A[i] < mid)
                countLess++ ;
            else if (A[i] == mid)
                countEq++ ;
        }
        
        if (countLess < B && countLess + countEq >= B)
            return mid ;
        else if (countLess >= B)
            high = mid - 1 ;
        else
            low = mid + 1 ;
    }
}

