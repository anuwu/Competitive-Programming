vector<int> Solution::prevSmaller(vector<int> &A) 
{
    int i ;
    vector<int> ans (A.size(), -1) ;
    stack<pair<int, int>> st ;
    
    i = A.size() - 1 ;
    st.push (make_pair (A[i], i)) ;
    for (--i; i >= 0 ; i--)
    {
        if (A[i] < st.top().first)
        {
            while(!st.empty() && A[i] < st.top().first)
            {
                ans[st.top().second] = A[i] ;
                st.pop () ;
            }
        }
            
        st.push (make_pair (A[i], i)) ;
    }
    
    return ans ;
}
