#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void flip (vector<int> &A)
{
    if (A.size () == 1)
    {
        cout << 1 << "\n" ;
        return ;
    }
    else if (A.size() == 2)
    {
        int pr ;
        if (A[0] == 1 || A[1] == 1)
            pr = 2 ;
        else
            pr = 1 ;
            
        cout << pr << "\n" ;
        return ;
    }
    
    int i, j, sum, prev, tmp, prefixEnd, N = A.size() ;
    int endsum, minsum ;
    
    A.insert (A.begin(), 0) ;
    sum = 0 ;
    for (i = 1 ; i <= N ; i++)
    {
        sum += A[i] ;
        A[i] = sum ;
    }
    prefixEnd = A[N] ;
    
    prev = 0 ;
    for (i = 1 ; i <= N ; i++)
    {
        tmp = 2*A[i] - i ;
        A[i] = tmp - prev ;
        prev = tmp ;
    }
    
    minsum = endsum = A[0] ;
    for (i = 1 ; i <= N ; i++)
    {
        if (endsum > 0)
            endsum = A[i] ;
        else
        {
            endsum += A[i] ;
            minsum = min (minsum, endsum) ;
        }
    }

    cout << prefixEnd - minsum << "\n" ;
}

int main() 
{
	int noTest, N, in, i, j ;
	vector<int> tc ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N ;
	    for (j = 0 ; j < N ; j++)
	    {
	        cin >> in ;
	        tc.push_back (in) ;
	    }
	    
	    flip (tc) ;
	    tc.clear () ;
	}
	
	return 0;
}
