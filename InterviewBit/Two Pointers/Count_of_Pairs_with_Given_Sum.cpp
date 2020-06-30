int Solution::solve(vector<int> &A, int B) 
{
    int i, j, l, r, lastl, lastr, cnt, N = A.size() ;
    
    cnt = 0 ;
    i = 0 ;
    j = N-1 ;
    while (i < j)
    {
        if (A[i] + A[j] > B)
            j-- ;
        else if (A[i] + A[j] < B)
            i++ ;
        else
        {
            lastl = A[i] ;
            l = 0 ;
            while (A[i] == lastl)
            {
                i++ ;
                l++ ;
            }
            
            lastr = A[j] ;
            r = 0 ;
            while (A[j] == lastr)
            {
                j-- ;
                r++ ;
            }
            
            cnt += (l*r) ;
        }
    }
    
    return cnt ;
}

