class Solution {
public:
    int subarraySum(vector<int>& A, int key) 
    {
        int i, cnt, N = A.size() ;
        unordered_map<int,int> s ;
        
        for (i = 1 ; i < N ; i++)
            A[i] += A[i-1] ;   
        
        cnt = 0 ;
        for (i = 0 ; i < N ; i++)
        {
            if (s.find(A[i]-key) != s.end())
                cnt += s[A[i]-key] ;
            if (A[i] == key)
                cnt++ ;
            
            if (s.find(A[i]) == s.end())
                s[A[i]] = 1 ;
            else
                s[A[i]]++ ;
        }
        
        return cnt ;
    }
};
