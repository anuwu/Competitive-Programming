void subsetter (int ind, vector<int> &A, vector<int> sub, vector<vector<int>> &ans)
{
    ans.push_back (sub) ;
    
    vector<int>::iterator it ;
    for (int i = ind + 1 ; i < A.size() ; i++)
    {
        sub.push_back (A[i]) ;
        subsetter (i, A, sub, ans) ;
        
        it = sub.end() - 1 ;
        sub.erase (it) ;
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) 
{
    sort (A.begin(), A.end()) ;
    vector<int> sub ;
    vector<vector<int>> ans ;
    
    subsetter (-1, A, sub, ans) ;
    return ans ;
}

