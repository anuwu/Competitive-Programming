vector<int> Solution::lszero(vector<int> &A) 
{
    int i, len, maxlen, ind, indleft, indright, N = A.size() ;
    long long sum ;
    vector<int> ans ;
    unordered_map<long long,int> m ;
    
    sum = 0 ;
    maxlen = INT_MIN ;
    for (i = 0 ; i < N ; i++)
    {
        sum += A[i] ;
        if (sum == 0)
        {
            if (i + 1 > maxlen)
            {
                indleft = 0 ;
                indright = i ;
                maxlen = i + 1 ;
            }
        }
        else
        {
            if (m.find (sum) == m.end ())
                m[sum] = i ;
            else
            {
                ind = m[sum] ;
                if (i - ind > maxlen)   
                {
                    indleft = ind + 1 ;
                    indright = i ;
                    maxlen = i - ind ;
                }
            }
        }
    }
    
    if (maxlen != INT_MIN)
    {
        for (i = indleft ; i <= indright ; i++)
            ans.push_back (A[i]) ;
    }

    return ans ;    
}

