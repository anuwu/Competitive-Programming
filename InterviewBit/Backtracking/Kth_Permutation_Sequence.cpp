vector<long long> fact ;

void perms (int firstun, int lastun, int count, int k, vector<int> &mask, string &ans)
{
    if (firstun == lastun)
    {
        ans.append (to_string (firstun)) ;
        return ;
    }
    
    int i, j, cnt, firstun_next, lastun_next ;
    long long f ;
    
    f = fact[mask.size() - count - 2] ;
    i = 1 ;
    while (i*f < k)
        i++ ;
        
    j = firstun ;
    cnt = 0 ;
    while (j <= lastun)
    {
        if (!mask[j])
        {
            cnt++ ;
            if (cnt == i)
                break ;
        }
        j++ ;
    }
    
    mask[j] = 1 ;
    ans.append (to_string (j)) ;
    if (j == firstun)
    {
        firstun_next = j + 1 ;
        while (mask[firstun_next])
            firstun_next++ ;
    }
    else if (j == lastun)
    {
        lastun_next = j - 1 ;
        while (mask[lastun_next])
            lastun_next-- ;
    }
    else
    {
        firstun_next = firstun ;
        lastun_next = lastun ;
    }

    perms (firstun_next, lastun_next, count+1, k - (i-1)*f, mask, ans) ;
}


string Solution::getPermutation(int A, int B) 
{
    fact.clear () ;
    fact = vector<long long> (A + 1, 1) ;
    
    int i ;
    vector<int> mask (A + 1, 0) ;
    string ans ;
    
    for (i = 2 ; i <= A ; i++)
        fact[i] = i * fact[i-1] ;
    
    if (B > 0)
        perms (1, A, 0, B, mask, ans) ;
        
    return ans ;
}

