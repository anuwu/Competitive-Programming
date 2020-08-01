int Solution::solve(string A) 
{
    int i, l = A.length() ;
    stack<char> s ;
    
    for (i = 0 ; i < l ; i++)
    {
        if (A[i] == '(')
            s.push ('(') ;
        else
        {
            if (!s.empty() && s.top() == '(')
                s.pop () ;
            else
                s.push (')') ;
        }
    }
    
    return s.size() ;
}
