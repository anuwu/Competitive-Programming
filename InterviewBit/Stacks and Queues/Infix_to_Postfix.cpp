string Solution::solve(string A) 
{
    int i, L = A.length() ;
    string ans ("") ;
    stack<char> s ;
    unordered_map<char,int> pred ;
    
    pred['^'] = 2 ;
    pred['*'] = 1 ;
    pred['/'] = 1 ;
    pred['+'] = 0 ;
    pred['-'] = 0 ;
    
    for (i = 0 ; i < L ; i++)
    {
        if (isalpha (A[i]))
            ans.push_back (A[i]) ;
        else if (A[i] == '(')
            s.push ('(') ;
        else if (A[i] == ')')
        {
            while (s.top() != '(')
            {
                ans.push_back (s.top()) ;
                s.pop () ;
            }
            s.pop () ;
        }
        else
        {
            if (pred[A[i]] > pred[s.top()])
                s.push (A[i]) ;
            else
            {
                while (!s.empty() && s.top() != '(' && pred[s.top()] >= pred[A[i]])
                {
                    ans.push_back (s.top()) ;
                    s.pop () ;
                }
                s.push (A[i]) ;
            }
        }
    }
    
    while (!s.empty ())
    {
        ans.push_back (s.top()) ;
        s.pop () ;
    }
    

    return ans ;
}

