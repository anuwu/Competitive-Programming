#include <bits/stdc++.h>

int Solution::singleNumber(const vector<int> &A) 
{
    int i, b, N, cnt ;
    bitset<32> bits ;
    
    for (b = 0 ; b < 32 ; b++)
    {
        cnt = 0 ;
        for (i = 0 ; i < A.size() ; i++)
        {
            if (A[i] & (1 << b))
            {
                cnt++ ;
                cnt %= 3 ;
            }
        }
        
        bits[b] = cnt ;
    }
    
    return bits.to_ulong() ;
}
