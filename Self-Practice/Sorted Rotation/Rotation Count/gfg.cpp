// Binary Search based C++ program to find number 
// of rotations in a sorted and rotated array. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Returns count of rotations for an array which 
// is first sorted in ascending order, then rotated 
int countRotations(vector<int> &arr, int low, int high) 
{ 
    // This condition is needed to handle the case 
    // when the array is not rotated at all 
    if (high < low) 
        return 0; 
  
    // If there is only one element left 
    if (high == low) 
        return low; 
  
    // Find mid 
    int mid = low + (high - low)/2; /*(low + high)/2;*/
  
    // Check if element (mid+1) is minimum element. 
    // Consider the cases like {3, 4, 5, 1, 2} 
    if (mid < high && arr[mid+1] < arr[mid]) 
       return (mid+1); 
  
    // Check if mid itself is minimum element 
    if (mid > low && arr[mid] < arr[mid - 1]) 
       return mid; 
  
    // Decide whether we need to go to left half or 
    // right half 
    if (arr[high] > arr[mid]) 
       return countRotations(arr, low, mid-1); 
  
    return countRotations(arr, mid+1, high); 
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

        cout << countRotations (tc, 0, N-1) << "\n" ;
        tc.clear () ;
    }

    return 0 ;
}