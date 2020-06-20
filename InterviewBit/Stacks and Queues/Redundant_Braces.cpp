int Solution::braces(string A) 
{
    stack<char> s ;
    int i ;
    
    for (i = 0 ; i < A.length() ; i++)
    {
        if (A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/')
            s.push ('o') ;
        else if (A[i] == '(')
            s.push ('(') ;
        else if (A[i] == ')')
        {
            if (s.top() == '(')
                return 1 ;
            else
            {
                while (s.top() != '(')
                    s.pop () ;
                s.pop () ;
            }
        }
        else
            continue ;
    }
    
    return 0 ;
}
