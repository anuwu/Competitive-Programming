void combinations (int num, int cnt, int B, int A, vector<int> comb, vector<vector<int>> &ans)
{
    if (cnt == B)
    {
        ans.push_back (comb) ;
        return ;
    }
    
    int lo, hi, rightcnt ;
    vector<int>::iterator it ;
    
    hi = (A + 1) - (B - cnt) ;
    for (lo = num+1 ; lo <= hi ; lo++)
    {
        comb.push_back (lo) ;
        combinations (lo, cnt+1, B, A, comb, ans) ;
        it = comb.end() - 1 ;
        comb.erase (it) ;
    }
}


vector<vector<int> > Solution::combine(int A, int B) 
{
    vector<int> comb ;
    vector<vector<int>> ans ;
    
    combinations (0, 0, B, A, comb, ans) ;
    
    return ans ;
}

