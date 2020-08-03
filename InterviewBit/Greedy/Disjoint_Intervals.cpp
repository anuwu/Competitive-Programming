int intervalLess (vector<int> &v1, vector<int> &v2)
{
    if (v1[1] < v2[1])
        return 1 ;
    else if (v1[1] > v2[1])
        return 0 ;
    else
        return v1[0] < v2[0] ;
}

int Solution::solve(vector<vector<int> > &A) 
{
    if (!A.size())
        return 0 ;
    else if (A.size() == 1)
        return 1 ;
    
    int i, j, cnt, N = A.size() ;
    sort (A.begin(), A.end(), intervalLess) ;
    
    cnt = 0 ;
    i = 0  ;
    do
    {
        cnt++ ;
        j = i ;
        do j++ ; while (j < N && !(A[j][1] > A[i][1] && A[j][0] > A[i][1])) ;
        
        i = j ;
    } while (i < N) ;
    
    return cnt ;
}
