int Solution::nchoc(int A, vector<int> &B) 
{
    int i, tm, maxchoc ;
    long long sumchoc, mod ;
    priority_queue<int> pq ;
    
    for (i = 0 ; i < B.size () ; i++)
        pq.push (B[i]) ;
    
    mod = (int)pow(10, 9) + 7 ;
    sumchoc = 0 ;
    for (tm = 0 ; tm < A ; tm++)
    {
        maxchoc = pq.top () ;
        sumchoc += maxchoc ;
        sumchoc %= mod ;
        pq.pop () ;
        pq.push (maxchoc/2) ;
    }
    
    return sumchoc ;
}

