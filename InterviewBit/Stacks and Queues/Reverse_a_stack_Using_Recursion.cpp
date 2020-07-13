
void revArr (vector<int> &A, int i, vector<int> &ans)
{
    if (i == -1)
        return ;
        
    ans.push_back (A[i]) ;
    revArr (A, i-1, ans) ;
}

vector<int> Solution::solve(vector<int> &A) 
{
    vector<int> ans ;
    revArr (A, A.size() - 1, ans) ;
    return ans ;
}

