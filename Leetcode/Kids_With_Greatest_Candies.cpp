class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& A, int extraCandies) 
    {
        int i, maxcand, N = A.size() ;
        vector<bool> ans (N, false) ;
        
        maxcand = A[0] ;
        for (i = 1 ; i < N ; i++)
            if (A[i] > maxcand)
                maxcand = A[i] ;
        
        for (i = 0 ; i < N ; i++)
            if (maxcand - A[i] <= extraCandies)
                ans[i] = true ;
        
        return ans ;
        
    }
};
