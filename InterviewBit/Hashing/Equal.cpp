
void updateAns (pair<int,int> p1, pair<int,int> p2, vector<int> &ans)
{
    if (p1.first >= p2.first || p1.second == p2.second || p1.second == p2.first)
        return ;
    
    if (!ans.size())
    {
        ans.push_back (p1.first) ;
        ans.push_back (p1.second) ;
        ans.push_back (p2.first) ;
        ans.push_back (p2.second) ;
    }
    else
    {
        if (p1.first < ans[0])
        {
            ans[0] = p1.first ;
            ans[1] = p1.second ;
            ans[2] = p2.first ;
            ans[3] = p2.second ;
        }
        else if (p1.first == ans[0])
        {
            if (p1.second < ans[1])
            {
                ans[1] = p1.second ;
                ans[2] = p2.first ;
                ans[3] = p2.second ;
            }
            else if (p1.second == ans[1])
            {
                if (p2.first < ans[2])
                {
                    ans[2] = p2.first ;
                    ans[3] = p2.second ;
                }
                else if (p2.first == ans[2] && p2.second < ans[3])
                    ans[3] = p2.second ;
            }
        }
    }
}

vector<int> Solution::equal(vector<int> &A) 
{
    int i, j, sum, N = A.size() ;
    unordered_map <int, pair<int,int>> s ;
    vector<int> ans ;
    
    for (i = 0 ; i < N ; i++)
    {
        for (j=i+1 ; j < N ; j++)
        {
            sum = A[i] + A[j] ;
            if (s.find (sum) != s.end ())
                updateAns (s[sum], make_pair (i, j), ans) ;
            else
                s[sum] = make_pair (i, j) ;
        }
    }
    
    return ans ;
}

