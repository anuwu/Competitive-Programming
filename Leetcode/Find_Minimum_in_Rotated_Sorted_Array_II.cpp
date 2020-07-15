class Solution {
public:
    int findMin(vector<int>& arr)
    {
        int low, high, mid, N = arr.size() ;

        low = 0 ;
        high = arr.size() - 1 ;
        while(low < high) 
        { 
            int mid = low + (high - low)/2; 
            if (arr[mid] == arr[low]) 
            {
                if (arr[low+1] >= arr[low])     
                    low++ ; 
                else
                    break ;
            }
            else if(arr[mid] < arr[low])  // Left increasing sequence is more dominating, decrease it.
                high = mid - 1; 
            else                           // Right increasing sequence is dominating, decrease it.
                low = mid;                // If monotonically increasing, then high will converge down to low
        } 
        
        return arr[(low+1)%N] ;
    }
};
