int Solution::solve(vector<int> &A) 
{
    sort (A.begin(), A.end()) ;
    if (A[A.size()-1] == 0) return 1 ;
    
    int i, j ;
    
    i = 0 ;
    do
    {
        j = i ;
        do
        {
            j++ ;
            if (j >= A.size ())
                return -1 ;
                
        } while (A[j] == A[i]) ;
        
        if (A.size() - j == A[i])
            return 1 ;
        else
            i = j ;
    } while (i < A.size ()) ;
    
    return -1 ;
}
