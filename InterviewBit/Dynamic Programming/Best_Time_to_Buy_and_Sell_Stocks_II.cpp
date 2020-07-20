int Solution::maxProfit(const vector<int> &A) 
{
    if (A.size() < 2)
        return 0 ;
        
    int i, j, profit, N = A.size() ;
    
    profit = 0 ;
    i = 1 ;
    do
    {
        while (i < N && A[i-1] >= A[i])             // stop when A[i-1] < A[i]
            i++ ;
        
        if (i == N)
            break ;
        
        j = i ;
        i-- ;
        while (j < N && A[j-1] <= A[j])             // stop when A[j-1] > A[j]
            j++ ;
        
        if (j == N)
        {
            profit += A[N-1] - A[i] ;
            break ;
        }
        
        profit += A[j-1] - A[i] ;
        i = j ;
    } while (true) ;
    
    
    return profit ;
}

