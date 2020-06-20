int Solution::isValid(string A) 
{
    stack<char> s ;
    int i ;
    char match ;
    
    s.push (A[0]) ;
    for (i = 1 ; i < A.length() ; i++)
    {
        if (A[i] == '(' || A[i] == '[' || A[i] == '{')
            s.push (A[i]) ;
        else
        {
            if (A[i] == ')') match = '(' ;
            if (A[i] == ']') match = '[' ;
            if (A[i] == '}') match = '{' ;
            
            if (s.top () != match)
                return 0 ;
            else
             s.pop () ;
        }
    }
    
    return 1 ;
}
