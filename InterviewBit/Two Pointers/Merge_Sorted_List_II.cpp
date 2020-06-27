void Solution::merge(vector<int> &A, vector<int> &B) 
{
    int i, j, lenA, lenB, k ;
    vector<int> ans ;
    
    lenA = A.size () ;
    lenB = B.size () ;

    ans.reserve (lenA + lenB) ;
    k = 0 ;
    i = 0 ;
    j = 0 ;
    while (i < lenA && j < lenB)
    {
        if (A[i] < B[j])
        {
            ans.push_back (A[i]) ;
            i++ ;
        }
        else
        {
            ans.push_back (B[j]) ;
            j++ ;
        }
        k++ ;
    }
    
    if (i < lenA)
        ans.insert (ans.end(), A.begin() + i, A.end ()) ;
    if (j < lenB)
        ans.insert (ans.end(), B.begin() + j, B.end()) ;
    
    A = ans ;
}

