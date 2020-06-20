
int Solution::evalRPN(vector<string> &A) 
{
    stack<int> s ;
    int i, op1, op2 ;
    
    for (i = 0 ; i < A.size () ; i++)
    {
        if (A[i][0] == '+')
        {
            op1 = s.top () ; s.pop () ;
            op2 = s.top () ; s.pop () ;
            s.push (op1 + op2) ;
        }
        else if (A[i][0] == '-')
        {
            op1 = s.top () ; s.pop () ;
            op2 = s.top () ; s.pop () ;
            s.push (op2 - op1) ;
        }
        else if (A[i][0] == '*')
        {
            op1 = s.top () ; s.pop () ;
            op2 = s.top () ; s.pop () ;
            s.push (op1 * op2) ;
        }
        else if (A[i][0] == '/')
        {
            op1 = s.top () ; s.pop () ;
            op2 = s.top () ; s.pop () ;
            s.push (op2 / op2) ;
        }
        else
        {
            printf ("%d\n", stoi(A[i])) ;
            s.push (stoi(A[i])) ;
        }
    }
    
    return s.top () ;
}
