class Solution {
public:
    void rotate(vector<int>& A, int k) 
    {
        int i, ind, tmp1, tmp2, lim, N = A.size() ;
        
        k = k % N ;
        if (k == 0)
            return ;
        
        lim = __gcd (N, k) ;
        
        for (i = 0 ; i < lim ; i++)
        {
            ind = i ;
            tmp1 = A[ind] ;
            ind += k ;
            
            do
            {
                tmp2 = tmp1 ;
                tmp1 = A[ind] ;
                A[ind] = tmp2 ;

                ind = (ind + k) % N ;
            } while (ind != i) ;

            A[i] = tmp1 ;
        }
    }
};
