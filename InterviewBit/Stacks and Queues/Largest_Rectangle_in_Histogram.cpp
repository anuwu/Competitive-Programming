int Solution::largestRectangleArea(vector<int> &A) 
{
    int i, maxarea, area, leftmost ;
    stack<pair<int,int>> st ;
    pair<int, int> top ;
    
    st.push (make_pair (A[0], 0)) ;
    maxarea = 0 ;
    leftmost = 0 ;
    for (i = 1 ; i < A.size () ; i++)
    {
        if (A[i] > st.top().first)
        {
            st.push (make_pair (A[i], i)) ;
            continue ;
        }
        
        if (A[i] < st.top().first)
        {
            top = st.top() ;
            while (top.first > A[i])
            {
                area = top.first * (i - top.second) ;
                if (area > maxarea)
                    maxarea = area ;
                    
                st.pop () ;
                if (st.empty ())
                    break ;
                else
                    top = st.top () ;
            }
            
            st.push (make_pair (A[i], top.second)) ;
        }
    }
    
    while (!st.empty ())
    {
        top = st.top() ;
        area = top.first * (i - top.second) ;
        if (area > maxarea)
            maxarea = area ;
        
        st.pop () ;
    }
    
    return maxarea ;
}

