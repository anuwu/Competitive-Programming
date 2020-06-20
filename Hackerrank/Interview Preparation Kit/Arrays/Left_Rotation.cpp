vector<int> rotLeft(vector<int> a, int d) 
{
    vector<int> ans ;
    d %= a.size() ;
    for (int i = 0 ; i < a.size() ; i++)
     ans.push_back (a[(i+d) % a.size()]) ;

    return ans ;
}