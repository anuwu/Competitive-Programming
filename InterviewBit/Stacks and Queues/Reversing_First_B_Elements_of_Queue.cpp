vector<int> Solution::solve(vector<int> &A, int B) 
{
    int i ;
    stack<int> st ;
    for (i = 0 ; i < B ; i++)
        st.push (A[i]) ;
        
    for (i = 0 ; i < B ; i++)
    {
        A[i] = st.top () ;
        st.pop () ;
    }
    
    return A ;
}

