int intabs (int x)
{
    if (x < 0)
        return -x ;
    else
        return x ;
}

int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    if (A.size () == 0 || A.size() == 1)
        return 0 ;
        
    int i, dist = 0 ;
    
    for (i = 1 ; i < A.size () - 1 ; i++)
        dist += max(intabs (A[i+1] - A[i]), intabs (B[i+1] - B[i])) ;
        
    return dist ;
}
