int Solution::trap(const vector<int> &A) 
{
    int water, N, i, base, height ;
    stack<pair<int,int>> st ;
    
    N = A.size() ;
    water = 0 ;
    i = 0 ;
    while (i < N - 1 && A[i+1] >= A[i])
        i++ ;
        
    if (i >= N - 2)
        return 0 ;
    
    st.push (make_pair (A[i], i)) ;
    i++ ;
    for ( ; i < N ; i++)
    {
        if (A[i] > st.top().first)
        {
            base = st.top().first ;
            st.pop () ;
            while (!st.empty() && A[i] > st.top().first)
            {
                height = st.top().first ;
                water += (height - base) * (i - st.top().second - 1) ;
                base = height ;
                
                st.pop () ;
            } 
            
            if (!st.empty ())
                water += (A[i] - base) * (i - st.top().second - 1) ;
        }
        
        st.push (make_pair (A[i], i)) ;
    }
    
    return water ;
}
