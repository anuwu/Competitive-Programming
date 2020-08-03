class Solution {
public:
    bool canJump(vector<int>& A) 
    {
        int i, maxreach, N = A.size() ;
        
        maxreach = 0 ;
        for (i = 0 ; i <= maxreach ; i++)
        {
            maxreach = max (maxreach, i + A[i]) ;
            if (maxreach >= N-1)
                return true ;
        }
    
        return false ;    
    }
};
