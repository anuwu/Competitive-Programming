int getCnt (vector<int> &A, int S)
{
    int i, j, sum, cnt, N = A.size() ;
    
    i = 0 ;
    j = 0 ;
    sum = A[0] ;
    cnt = 0 ;
    while (j < N)
    {
        if (sum <= S)
        {
            j++ ;
            sum += A[j] ;
            
            cnt += (j - i) ;
        }
        else
        {
            if (i == j)
            {
                i++ ; 
                j++ ;
                if (i < N)
                    sum = A[i] ;
            }
            else
            {
                sum -= A[i] ;
                i++ ;
            }
        }
    }
    
    return cnt ;
}

int Solution::numRange(vector<int> &A, int B, int C) 
{
    return getCnt (A, C) - getCnt (A, B-1) ;
}
