stack<pair<int,int>> s ;
MinStack::MinStack() {
    stack<pair<int,int>> empty ;
    s = empty ;
}

void MinStack::push(int x) 
{
    if (s.empty () || x < s.top().second)
        s.push (make_pair(x, x)) ;
    else
        s.push (make_pair (x, s.top().second));
}

void MinStack::pop() 
{
    if (!s.empty ())
        s.pop () ;
}

int MinStack::top() {
    return s.empty () ? -1 : s.top().first ;
}

int MinStack::getMin() 
{
    return s.empty () ? -1 : s.top().second ;
}


