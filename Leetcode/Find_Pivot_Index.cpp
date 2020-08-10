class Solution {
public:
    int pivotIndex(vector<int>& A) 
    {
        int i, pivot, N = A.size() ;
        
        for (i = 1 ; i < N ; i++)
            A[i] += A[i-1] ;
        
        pivot = -1 ;
        for (i = 0 ; i < N ; i++)
            if ((i - 1 >= 0 ? A[i-1] : 0) == A[N-1] - A[i])
            {
                pivot = i ;
                break ;
            }
        
        return pivot ;
    }
};
