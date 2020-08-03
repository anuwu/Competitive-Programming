class Solution {
public:
    int maxProfit(vector<int>& A) 
    {
        if (A.size () < 2)
            return 0 ;
        
        int i, runmin, maxdiff, N = A.size() ;

        maxdiff = 0 ;
        runmin = A[0] ;
        for (i = 1 ; i < N ; i++)
        {
            if (A[i] < runmin)
                runmin = A[i] ;
            else if (A[i] - runmin > maxdiff)
                maxdiff = A[i] - runmin ;
        }
        
        return maxdiff ;
    }
};
