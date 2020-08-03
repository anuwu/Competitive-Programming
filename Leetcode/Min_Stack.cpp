class MinStack {
public:
    stack<pair<int, int>> s ;
    MinStack() {
        ;
    }
    
    void push(int x) 
    {
        if (s.empty () || x < s.top().second)
            s.push (make_pair(x, x)) ;
        else
            s.push (make_pair (x, s.top().second));
    }
    
    void pop() {
        s.pop () ;
    }
    
    int top() {
        return s.top().first ;
    }
    
    int getMin() {
        return s.top().second ;
    }
};