class Solution {
public:
    string restoreString(string s, vector<int>& indices) 
    {
        int l = s.length() ;
        string ans (l, 0) ;
        
        for (int i = 0 ; i < l ; i++)
            ans[indices[i]] = s[i] ;
        
        return ans ;
    }
};
