int Solution::solve(vector<int> &A, int B) 
{
    int i, j, cnt, sz, sum, N = A.size() ;

    sz = 0 ;
    cnt = 0 ;
    i = 0 ;
    j = 0 ;
    sum = A[0] ;
    do
    {
        if (sum < B)
        {
            cnt += (j - i + 1) ;
            
            j++ ;
            sum += A[j] ;
        }
        else
        {
            sum -= A[i] ;
            i++ ;
        }
        
    } while (j < N) ;
    
    return cnt ;
}

