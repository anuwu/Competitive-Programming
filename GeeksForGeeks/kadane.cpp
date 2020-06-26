#include <stdio.h>
#include <bits/stdc++.h>

using namespace std ;

void kadane (vector<int> &A)
{
    if (A.size () == 0)
    {
        cout << 0 << "\n" ;
        return ;
    }
    
    int i, ans, sumEnd ;
    ans = A[0] ;
    sumEnd = A[0] ;
    
    for (i = 1 ; i < A.size () ; i++)
    {
        if (sumEnd <= 0)
            sumEnd = A[i] ;
        else
            sumEnd += A[i] ;
            
        ans = max (sumEnd, ans) ;
    }
    
    printf ("%d\n", ans) ;
}

int main() 
{
	int noTest, in, i, j, N ;
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
	    
	    kadane (tc) ;
	    tc.clear () ;
	}
	
	return 0;
}
