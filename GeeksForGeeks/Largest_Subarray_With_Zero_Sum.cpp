#include <bits/stdc++.h>

int maxLen(int A[], int n)
{
    int i, len, maxlen, ind ;
    long long sum ;
    vector<long long> arr (n, 0) ;
    unordered_map<long long,int> m ;
    
    sum = 0 ;
    maxlen = INT_MIN ;
    for (i = 0 ; i < n ; i++)
    {
        sum += A[i] ;
        if (sum == 0)
        {
            if (i + 1 > maxlen)
                maxlen = i + 1 ;
        }
        else
        {
            if (m.find (sum) == m.end ())
                m[sum] = i ;
            else
            {
                ind = m[sum] ;
                if (i - ind > maxlen)   
                    maxlen = i - ind ;
            }
        }
    }
    
    if (maxlen != INT_MIN)
        return maxlen ;
    else
        return 0 ;
    
}
