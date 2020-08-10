#define MOD 1000000007

int Solution::strStr(const string haystack, const string needle) 
{
    if (!needle.length() || !haystack.length())
        return -1 ;
    if (needle.length() > haystack.length())
        return -1 ;
    
    int i, j, k, M = needle.length(), N = haystack.length() ;
    long long hayhash, needlehash ;     
    bool match ;
    vector<int> place (M, 1) ;
       
    for (i = M-2 ; i >= 0 ; i--)
        place[i] = (place[i+1] * 10) % MOD ;
    
    needlehash = hayhash = 0 ;
    for (i = 0 ; i < M ; i++)
    {
        hayhash = (hayhash + (((long long)haystack[i] * place[i]) % MOD)) % MOD ;
        needlehash = (needlehash + (((long long)needle[i] * place[i]) % MOD)) % MOD ;
    }
    
    j = M-1 ;
    do
    {
        if (needlehash == hayhash)
        {
            k = j - M + 1 ;
            i = 0 ;
            match = true ;
            do
            {
                if (needle[i] != haystack[k])
                {
                    match = false ;
                    break ;
                }
                
                i++ ;
                k++ ;
            } while (i < M) ;
            
            if (match)
                return j - M + 1 ;
        }
        
        j++ ;
        if (j == N)
            break ;
            
        hayhash = (hayhash - (((long long)haystack[j-M]*place[0]) % MOD)) % MOD ;
        if (hayhash < 0)
            hayhash = ((hayhash % MOD) + MOD) % MOD ;
        hayhash = (hayhash*10) % MOD ;
        hayhash = (hayhash + (long long)haystack[j]) % MOD ;
    } while (true) ;
    
    
    return -1 ;
}

