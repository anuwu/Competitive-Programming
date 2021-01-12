class Solution {
public:
    vector<int> get_lps (string s)
    {
        int len = s.length(), j, i ;
        vector<int> pref(len, -1) ;
        
        i = -1 ;
        for (j = 1 ; j < len ; j++)
        {
            while (i != -1 && s[i+1] != s[j])
                i = pref[i] ;
                
            if (s[i+1] == s[j])
            {
                i++ ;
                pref[j] = i ;
            }
            else
                pref[j] = -1 ;
        }
        
        return pref ;
    }
    
    int strStr(string haystack, string needle) 
    {
        if (needle.length() == 0)
            return 0 ;
        
        int i, j, len = haystack.length() ;
        vector<int> lps ;
        
        lps = get_lps(needle) ;
        j = -1 ;
        for (i = 0 ; i < len ; i++)
        {
            if (haystack[i] == needle[j+1])
                j++ ;
            else
            {
                while (j != -1 && haystack[i] != needle[j+1])
                    j = lps[j] ;
                
                if (haystack[i] == needle[j+1])
                    j++ ;
            }
            
            if (j == needle.length() - 1)
                return i - j ;
        }
        
        return -1 ;
    }
};
