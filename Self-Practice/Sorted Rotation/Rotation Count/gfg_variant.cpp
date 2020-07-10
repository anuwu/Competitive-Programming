#include<bits/stdc++.h> 
using namespace std; 

int findMin(vector<int> &arr)  
{  
	int low, high, mid, fin, N = arr.size() ;

    low = 0 ;
    high = arr.size() - 1 ;
    while(low < high) 
    { 
        int mid = low + (high - low)/2; 
        if (arr[mid] == arr[low])           // If this falls off, then it's a fully duplicated array
        {
            if (arr[low+1] >= arr[low])
            	low++ ;
            else
            	break ;
        }
        else if(arr[mid] < arr[low])        // Right increasing sequence is dominating, decrease it.
            high = mid - 1 ; 
        else                                // Left increasing sequence is dominating, set it there.
            low = mid; 
    } 
    

    fin = (low+1)%N ;
    printf ("Sorted array starts at A[%d] = %d\n", fin, arr[fin]) ;
}  
  
// Driver code 
int main ()
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

        findMin (tc) ;
        tc.clear () ;
    }

    return 0 ;
}