int Solution::solve(vector<int> &A) 
{
    int maxnum, minnum, N = A.size() ;
    
    maxnum = minnum = A[0] ;
    for (int i = 1 ; i < N ; i++)
    {
        if (A[i] < minnum)
        {
            minnum = A[i] ;
            continue ;
        }
        else if (A[i] > maxnum)
            maxnum = A[i] ;
    }
    
    return minnum + maxnum ;
}

