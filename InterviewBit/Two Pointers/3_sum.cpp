int Solution::threeSumClosest(vector<int> &A, int B) 
{
    int i, l, r,  N = A.size() ;
    long long sum, diff, mindiff, target ;
    
    sort (A.begin(), A.end()) ;
    mindiff = INT_MAX ;
    for (i = 0 ; i < N ; i++)
    {
        l = i+1 ;
        r = N-1 ;
        target = B - A[i] ;
        
        while (l < r)
        {
            diff = (long long)abs((long long)A[l] + (long long)A[r] - target) ; 
            if (diff < mindiff)
            {
                mindiff = diff ;
                sum = (long long)A[i] + (long long)A[l] + (long long)A[r] ;
            }
            
            if ((long long)A[l] + (long long)A[r] < target)
                l++ ;
            else
                r-- ;
        }
    }
    
    return sum ;
}

