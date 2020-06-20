bool islowerInterval (Interval i1, Interval i2)
{
    return i1.start < i2.start ;
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    int i, last ;
    vector<Interval> A, ans ;
    A = intervals ;
    
    for (i = 0 ; i < A.size () ; i++)
    {
        if (islowerInterval (A[i], newInterval))
            ans.push_back (A[i]) ;
        else
            break ;
    }
    
    if (ans.size () == 0)
        ans.push_back (newInterval) ;
    else
    {
        last = ans.size () - 1 ;
        if (newInterval.start <= ans[last].end)
            ans[last].end = max (ans[last].end, newInterval.end) ;
        else
            ans.push_back (newInterval) ;
    }
    
    for ( ; i < A.size () ; i++)
    {
        last = ans.size () - 1 ;
        if (A[i].start <= ans[last].end)
            ans[last].end = max (ans[last].end, A[i].end) ;
        else
        {
            ans.insert (ans.end (), A.begin () + i, A.end ()) ;
            break ;
        }
    }
    
    return ans ;
}
