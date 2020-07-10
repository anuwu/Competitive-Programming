#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

int search(vector<int>& nums, int target) 
{
    int l, r, mid, N = nums.size() ;
    
    l = 0 ;
    r = N-1 ;
    while (l <= r)
    {
        mid = l + (r-l)/2 ;
        if (nums[mid] == target)
            return mid ;
        else
        {
            if (target == nums[l])
                return l ;
            if (target == nums[r])
                return r ;
            
            if (target > nums[l])
            {
                if (nums[mid] > target)
                    r = mid - 1 ;
                else if (nums[mid] < nums[l])
                    r = mid - 1;
                else
                    l = mid + 1 ;
            }
            else // target < nums[r]
            {
                if (nums[mid] < target)
                    l = mid + 1 ;
                else if (nums[mid] > nums[r])
                    l = mid + 1 ;
                else
                    r = mid - 1;
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