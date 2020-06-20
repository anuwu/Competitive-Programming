vector<int> Solution::twoSum(const vector<int> &A, int B) 
{
    vector<int> ans ;
    int i, index1, index2 ;
    
    if (A.size () == 0) return ans ;
    
    unordered_map <int, int> m ;
    m[A[0]] = 0 ;
    for (i = 1 ; i < A.size () ; i++)
    {
        if (m.find (B - A[i]) != m.end ())
        {
            index1 = m[B-A[i]] ;
            index2 = i ;
            ans.push_back (index1 + 1) ;
            ans.push_back (index2 + 1) ;
            
            break ;
        }
        
        if (m.find (A[i]) == m.end ()) m[A[i]] = i ;
    }
    
    return ans ;
}