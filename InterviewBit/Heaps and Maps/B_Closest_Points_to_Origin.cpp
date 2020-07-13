
bool pointLess (vector<int>&p1, vector<int>&p2)
{
    return p1[0]*p1[0] + p1[1]*p1[1] <= p2[0]*p2[0] + p2[1]*p2[1] ;
}

vector<vector<int>> Solution::solve(vector<vector<int>> &A, int B) 
{
    int i ;
    vector<vector<int>> ans ;
    sort (A.begin() , A.end(), pointLess) ;
    
    for (i = 0 ; i < B ; i++)
        ans.push_back (A[i]) ;
    
    return ans ;
}

