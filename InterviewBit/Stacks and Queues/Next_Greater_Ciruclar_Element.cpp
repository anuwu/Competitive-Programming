vector<int> Solution::solve(vector<int> &A) 
{
    int i, j, max, lst, N = A.size(), M ;
    
    vector<int> ans (N, -1) ;
    vector<int> detone ;
    stack<pair<int, int>> st ;
    
    detone.reserve (100) ;
    lst = N ;
    do
    {
        lst-- ;
        detone.push_back (A[lst]) ;
    } while (lst >= 0 && A[lst - 1] >= A[lst]) ;
        
    if (lst < 0)
    {
        for (i = N-1 ; A[i] != A[0] ; i--)
            ans[i] = A[0] ;
            
        return ans ;
    }
    
    M = detone.size() ;
    /********* STACK LOOP INIT ***********/
    j = 0 ;
    while (j < M && A[0] > detone[j])
    {
        ans[N - j - 1] = A[0] ;
        j++ ;
    }
    max = A[0] ;
    st.push (make_pair (A[0], 0)) ;
    /********* STACK LOOP INIT ***********/
    
    for (i = 1 ; i < N ; i++)
    {
        if (A[i] > max)
            max = A[i] ;
        
        while (j < M && A[i] > detone[j])
        {
            ans[N - j - 1] = A[i] ;
            j++ ;
        }
        if (A[i] > st.top().first)
        {
            while (!st.empty() && A[i] > st.top().first)
            {
                ans[st.top().second] = A[i] ;
                st.pop () ;
            }
        }
        
        st.push (make_pair (A[i], i)) ;
    }
    
    while (!st.empty () && st.top().second >= lst)
        st.pop () ;
    
    for (i = 0 ; i <= lst ; i++)
    {
        if (st.empty() || st.top().first == max)
            break ;
        
        while (!st.empty () && st.top().first != max && A[i] > st.top().first)
        {
            ans[st.top().second] = A[i] ;
            st.pop () ;
        }
    }
    
    return ans ;
}

