int Solution::majorityElement(const vector<int> &A)
{
    unordered_map<int, int> m ;
    int i, maxcnt, maxele, curr ;
    
    maxcnt = 0 ;
    for (i = 0 ; i < A.size() ; i++)
    {
        if (m.find (A[i]) == m.end ()) curr = m[A[i]] = 1 ;
        else curr = ++m[A[i]] ;
        
        if (curr > maxcnt)
        {
            maxcnt = curr ;
            maxele = A[i] ;
            
            if (maxcnt > A.size()/2) return maxele ;
        }
    }
}
