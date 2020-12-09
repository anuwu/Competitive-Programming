class Solution {
public:
    bool isSubsequence(string s, string t) 
    {        
        int N = s.length(), M = t.length() ;
        
        if (!N)
            return true ;
        
        int matched = 0 ;
        for (int i=0 ; i < M ; i++)
        {
            if (t[i] == s[matched])
                matched++ ;
            
            if (matched == N)
                return true ;
        }
        
        return false ;
    }
};
