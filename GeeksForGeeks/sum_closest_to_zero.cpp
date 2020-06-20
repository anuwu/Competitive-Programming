#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sumCloseZero (vector<int> &A, int N)
{
    if (N == 1)
    {
        cout << 2*A[0] << "\n" ;
        return ;
    }
    else if (N == 2)
    {
        cout << A[0] + A[1] << "n" ;
        return ;
    }
    
    int i, j, minabssum, minsum, sum ;
    bool initpos ;
    sort (A.begin(), A.end()) ;
    
    i = 0 ; j = A.size() - 1 ;
    minabssum = INT_MAX ;
    while (i != j)
    {
        sum = A[i] + A[j] ;
        if (sum > 0)
        {
            if (sum < minabssum)
            {
                minabssum = sum ;
                minsum = sum ;
            }
                
            j-- ;
        }
        else if (sum < 0)
        {
            if (minabssum + sum > 0)
            {
                minabssum = -sum ;
                minsum = sum ;
            }
                
            i++ ;
        }
        else
        {
            cout << 0 << "\n" ;
            return ;
        }
    }
    
    cout << minsum << "\n" ;
}

int main() 
{
	int i, j, in, noTest, N ;
	vector<int> arr ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N ;
	    for (j = 0 ; j < N ; j++)
	    {
	        cin >> in ;
	        arr.push_back (in) ;
	    }
	    
	    sumCloseZero (arr, N) ;
	    arr.clear () ;
	}
	return 0;
}
