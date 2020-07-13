int Solution::solve(vector<int> &A, int B) 
{
    int i, minpos, sum, negcnt, negsum, maxneg, N = A.size() ;
    unordered_map<int,int> mplus ;
    map<int,int> mneg ;
    map<int,int>::iterator it ;
    
    maxneg = INT_MIN ;
    minpos = INT_MAX ;
    negcnt = 0 ;
    sum = 0 ;
    negsum = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] >= 0)
        {
            if (A[i] < minpos)
                minpos = A[i] ;
            
            sum += A[i] ;
            if (mplus.find (A[i]) == mplus.end())
                mplus[A[i]] = 1 ;
            else
                mplus[A[i]]++ ;
        }
        else
        {
            if (A[i] > maxneg)
                maxneg = A[i] ;
            negcnt++ ;
            negsum += A[i] ;
            
            if (mneg.find (A[i]) == mneg.end())
                mneg[A[i]] = 1 ;
            else
                mneg[A[i]]++ ;
        }
    }
    
    if (B >= negcnt)
    {
        sum += (-negsum) ;
        maxneg *= -1 ;
        minpos = min (minpos, maxneg) ;
        
        B -= negcnt ;
        if (B % 2)
            sum -= 2*minpos ;
    }
    else
    {
        it = mneg.begin () ;
        while (B - it->second >= 0)
        {
            B -= it->second ;
            sum += (-it->first) * it->second ;
            negsum += (-it->first) * it->second ;
            
            it++ ;
        }
       
        if (B > 0)
        {
            sum += (-it->first) * B ;
            negsum += (-it->first) * B ;
        }
        
        sum += negsum ;
    }
    
    
    return sum ;
}

