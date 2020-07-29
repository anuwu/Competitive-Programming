int Solution::solve(vector<int> &A, int B) 
{
    int i, s, sum, maxsum, left, N = A.size() ;
    
    sum = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        sum += A[i] ;
        A[i] = sum ;
    }
    
    if (B == N)
        return sum ;
    
    left = N - B ;
    maxsum = sum - A[left-1] ;
    for (i = 0 ; i < N - left ; i++)
    {
        s = sum - (A[i+left] - A[i]) ;
        if (s > maxsum)
            maxsum = s ;
    }
    
    return maxsum ;
}

