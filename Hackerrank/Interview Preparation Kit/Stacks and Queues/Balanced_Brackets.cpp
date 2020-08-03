string isBalanced(string A) 
{
    int i, l = A.length() ;
    string yes("YES"), no("NO") ;
    stack<char> st ;

    st.push (A[0]) ;
    for (i = 1 ; i < l ; i++)
    {
        if (A[i] == '(' || A[i] == '[' || A[i] == '{')
            st.push (A[i]) ;
        else if (!st.empty())
        {
            if ((A[i] == ')' && st.top() == '(') || (A[i] == '}' && st.top() == '{') || (A[i] == ']' && st.top() == '['))
                st.pop () ;
            else
                return no ;
        }
        else
            return no ;
    }

    if (st.size())
        return no ;
    else
        return yes ;
}
