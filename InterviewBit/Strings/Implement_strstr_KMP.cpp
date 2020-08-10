#define MOD 1000000007

int Solution::strStr(const string haystack, const string needle) 
{
    int len, i, j, M = needle.length(), N = haystack.length() ;
    vector<int> lps (M, 0) ;
    
    len = 0 ;
    i = 1 ;
    while (i < M)
    {
        if (needle[i] == needle[len])
        {
            len++ ;
            lps[i] = len ;
            i++ ;
        }
        else
        {
            if (len != 0)
                len = lps[len-1] ;
            else
            {
                lps[i] = 0 ;
                i++ ;
            }
        }
    }
    
    i = j = 0 ;
    while (j < N)
    {
        if (needle[i] == haystack[j])
        {
            j++ ;
            i++ ;
        }
        
        if (i == M)
        {
            return j - M ;
            i = lps[i-1] ;
        }
        else if (j < N && needle[i] != haystack[j])
        {
            if (i != 0)
                i = lps[i-1] ;
            else
                j++ ;
        }
    }
    
    return -1 ;
}

