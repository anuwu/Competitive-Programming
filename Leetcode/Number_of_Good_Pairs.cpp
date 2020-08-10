class Solution {
public:
    int numIdenticalPairs(vector<int>& A) 
    {
        int i, cnt, N = A.size() ;
        unordered_map<int,int> m ;
        
        cnt = 0 ;
        for (i = 0 ; i < N ; i++)
        {
            if (m.find (A[i]) == m.end())
                m[A[i]] = 1 ;
            else
            {
                cnt += m[A[i]] ;
                m[A[i]]++ ;
            }
        }
        
        return cnt ;
    }
};
