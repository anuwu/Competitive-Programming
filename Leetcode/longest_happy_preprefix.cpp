class Solution {
public:
    string longestPrefix(string s)
    {        
        int i, j, len = s.length() ;
        vector<int> pref(len, -1) ;
        
        if (len < 2)
            return string() ;
        
        i = -1 ;
        // printf ("-1, ") ;
        for (j = 1 ; j < len ; j++)
        {
            if (s[i+1] == s[j])
            {
                i++ ;
                pref[j] = i ;
            }
            else
            {
                while (i != -1 && s[i+1] != s[j])
                    i = pref[i] ;
                
                if (s[i+1] != s[j])
                    pref[j] = -1 ;
                else
                {
                    i++ ;
                    pref[j] = i ;
                }
            }
            // printf ("%d, ", pref[j]) ;
        }
        
        
        return s.substr(0, pref[len-1] + 1) ;
    }
};
