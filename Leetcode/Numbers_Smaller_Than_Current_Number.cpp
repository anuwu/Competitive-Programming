class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& A) 
    {
        int savek, k, l = A.size() ;
        map<int,vector<int>> m ;
        vector<int> vec, emp, ans (l, 0) ;
        
        for (int i = 0 ; i < l ; i++)
        {
            if (m.find(A[i]) == m.end())
            {
                emp.clear () ;
                emp.push_back (i) ;
                m[A[i]] = emp ;
            }
            else
                m[A[i]].push_back (i) ;
        }
        
        k = 0 ;
        for (auto it = m.begin() ; it != m.end() ; it++)
        {
            vec = it->second ;
            savek = k ;
            for (int j = 0 ; j < (int)vec.size() ; j++, k++)
                ans[vec[j]] = savek ;
        }
        
        return ans ;
        
    }
};
