string Solution::solve(string A) 
{
    int i, j, len = A.length() ;
    stack<char> st ;
    
    st.push (A[0]) ;
    i = 1 ;
    while (i < len)
    {
        if (!st.empty() && A[i] == st.top())
        {
            j = i ;
            do j++ ; while (j < len && A[j] == A[i]) ;
            
            if ((j - i) % 2)
                st.pop () ;
            i = j ;
        }
        else
        {
            st.push (A[i]) ;
            i++ ;
        }
    }
    
    A.clear () ;
    if (!st.empty())
    {
        while (!st.empty ())
        {
            A.push_back (st.top()) ;
            st.pop () ;
        }   
        
        reverse (A.begin(), A.end()) ;
    }
    else
        A = string ("empty") ;
    
    return A ;
}

