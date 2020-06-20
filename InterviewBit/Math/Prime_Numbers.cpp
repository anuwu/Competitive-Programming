vector<int> Solution::sieve(int N) 
{
    int i, p, st ;
    vector<bool> arr(N , false) ;
    vector<int> ans ;
    
    p = 2 ;
    st = p*p ;
    while (st <= N)
    {
        while (st <= N)
        {
            arr[st - 1] = true ;
            st += p ;
        }
        
        do p++ ; while (arr[p - 1]) ;
            
        st = p*p ;    
    }
    
    for (i = 1 ; i < N ; i++)
        if (!arr[i])
            ans.push_back (i+1) ;
            
    return ans ;
}
