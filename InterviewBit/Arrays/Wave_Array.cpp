vector<int> Solution::wave(vector<int> &A) {
    sort (A.begin (), A.end ()) ;
    int tmp ;
    for (int i = 0 ; i < A.size () - 1 ; i += 2)
    {
        tmp = A[i] ;
        A[i] = A[i+1] ;
        A[i+1] = tmp ;
    }
    
    return A ;
}
