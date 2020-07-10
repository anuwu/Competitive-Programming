#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

int search(vector<int>& nums, int target) 
{
    int low, high, mid ;
    
    low = 0 ;
    high = nums.size() - 1 ;
    while (low <= high)
    {
        mid = low + (high - low)/2 ;
        if (nums[mid] == target)
            return mid ;
        else
        {
            if (target == nums[low])
                return low ;
            if (target == nums[high])
                return high ;
            
            if (target > nums[low])
            {
                if (nums[mid] > target)
                    high = mid - 1 ;
                else if (nums[mid] == nums[low])
                    low++ ;
                else if (nums[mid] > nums[low])
                    low = mid + 1 ;
                else
                    high = mid - 1 ;
                    
            }
            else // target < nums[high]
            {
                if (nums[mid] < target)
                    low = mid + 1 ;
                else if (nums[mid] == nums[high])
                     high-- ;
                else if (nums[mid] < nums[high])
                    high = mid - 1 ;
                else
                    low = mid + 1 ;
            }
        }
    }
    
    return -1 ;
}

int main ()
{
    int noTest, N, in, target, res, i, j ;
    vector<int> tc ;

    cin >> noTest ;
    for (i = 0 ; i < noTest ; i++)
    {
        cin >> N >> target ;
        for (j = 0 ; j < N ; j++)
        {
            cin >> in ;
            tc.push_back (in) ;
        }

        res = search (tc, target) ;
        if (res != -1)
            printf ("Element %d was found at position %d\n", target, res) ;
        else
            printf ("Element %d was not found\n", target) ;

        tc.clear () ;
    }

    return 0 ;
}