int Solution::maxSpecialProduct(vector<int> &A) 
{
    int i, j, N = A.size() ;
    long long prod, maxsprod ;
    vector<int> spec (N, -1) ;
    stack<pair<int, int>> sl, sr ;
    
    sl.push (make_pair (A[0], 0)) ;
    sr.push (make_pair (A[N-1], N-1)) ;
    maxsprod = 0 ;
    for (i = 1 , j = N - 2 ; i < N - 1 && j > 0 ; i++, j--)
    {
        while (!sl.empty() && sl.top().first <= A[i])
            sl.pop () ;
            
        if (!sl.empty ())
        {
            if (spec[i] == -1)
                spec[i] = sl.top().second ;
            else
            {
                prod = (long long) spec[i] * sl.top().second ;
                if (prod > maxsprod)
                    maxsprod = prod ;
            }
        }
        
        sl.push (make_pair (A[i], i)) ;
        
        while (!sr.empty() && sr.top().first <= A[j])
            sr.pop () ;
            
        if (!sr.empty ())
        {
            if (spec[j] == -1)
                spec[j] = sr.top().second ;
            else
            {
                prod = (long long) spec[j] * sr.top().second ;
                if (prod > maxsprod)
                    maxsprod = prod ;
            }
        }
        
        sr.push (make_pair (A[j], j)) ;
    }
    
    return maxsprod % ((int)pow(10,9) + 7);
}
