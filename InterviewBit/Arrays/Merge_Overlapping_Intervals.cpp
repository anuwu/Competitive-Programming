bool intervalComp (Interval i1, Interval i2)
{
    return i1.start < i2.start ;
}

vector<Interval> Solution::merge(vector<Interval> &A) 
{
    sort (A.begin (), A.end (), intervalComp) ;
    vector<Interval> ans ;
    ans.push_back (A[0]) ;
    
    int i, last ;
    for (i = 1 ; i < A.size () ; i++)
    {
        last = ans.size() - 1 ;
        if (A[i].start <= ans[last].end)
            ans[last].end = max (ans[last].end, A[i].end) ;
        else
            ans.push_back (A[i]) ;
    }
   
   return ans ;
}
