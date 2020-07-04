int Solution::solve(string A) 
{
    int i ;
    stack<char> s ;
    
    s.push (A[0]) ;
    for (i = 1 ; i < A.length() ; i++)
    {
        if (A[i] == ')')
        {
            if (s.empty () || s.top() != '(')
                return 0 ;
                
            s.pop () ;
        }
        else
            s.push ('(') ;
    }
    
    if (s.empty())
        return 1 ;
        
    return 0 ;
}

