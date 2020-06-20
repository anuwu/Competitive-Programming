int Solution::singleNumber(const vector<int> &A) {
    int i, ans = A[0] ;
    
    for (i = 1 ; i < A.size () ; i++)
        ans = ans ^ A[i] ;
        
    return ans ;
}
