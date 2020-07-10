/*****************************************************
* Note, the original GFG code will work for finding the
* minimum of the array, but it won't find the correct
* rotation count
*****************************************************/

#include<bits/stdc++.h> 
using namespace std; 

int findMin(vector<int> &arr)  
{  
    /********************************************************************
    * The idea of this sorting technique is that start of the sorted sequence
    * will be finally stored in 'high'. It is possible that 'low' can fall
    * off the left increasing end, however, high is constricted on the right
    * increasing sequence and this is enforced by the statement high = mid
    *********************************************************************/

	int low, high, mid ;

	low = 0 ;
	high = arr.size() - 1 ;
    while(low < high) 
    { 
        int mid = low + (high - low)/2; 
        if (arr[mid] == arr[high]) 
        {
            if (arr[high-1] <= arr[high])     
                high--; 
            else
                break ;
        }
        else if(arr[mid] > arr[high])  // Left increasing sequence is more dominating, decrease it.
            low = mid + 1; 
        else                           // Right increasing sequence is dominating, decrease it.
            high = mid;                // If monotonically increasing, then high will converge down to low
    } 

    printf ("Sorted array starts at A[%d] = %d\n", high, arr[high]) ;
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