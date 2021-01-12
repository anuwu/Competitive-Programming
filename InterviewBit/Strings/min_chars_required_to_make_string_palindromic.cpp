
int get_lps (string s)
{
    int i, j, len = s.length() ;
    vector<int> pref(len, -1) ;
    
    i = -1 ;
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
    }
    
    return pref[len-1] + 1 ;
}

int Solution::solve(string A)
{
    int len = A.length() ;
    string D = string(A) ;
    
    D.append("$") ;
    D.append(A) ;
    reverse(D.begin() + len + 1, D.end()) ;
    
    return len - get_lps(D) ;
}

