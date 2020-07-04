struct hash_pair 
{ 
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2> &pair) const
    {
        return (*this)(pair.first) ^ (*this)(pair.second);
    }

    template <class T>
    size_t operator() (const T &v) const
    {
        return hash<T>()(v);
    }
};


int Solution::solve(vector<int> &A, int B) 
{
    int i, j, other, min, max ;
    unordered_set<int> s ;
    unordered_set<pair<int,int>, hash_pair> uniq ;
    
    s.insert (A[0]) ;
    for (i = 1 ; i < A.size() ; i++)
    {
        other = B ^ A[i] ;
        if (s.find (other) != s.end ())
        {
            min = A[i] < B ? A[i] : B ;
            max = A[i] > B ? A[i] : B ;
            if (min != max)
                uniq.insert (make_pair (min, max)) ;
        }
        if (s.find(A[i]) == s.end())
            s.insert (A[i]) ;
    }
    
    return uniq.size() ;
}
