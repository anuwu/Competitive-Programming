int peakElement(int arr[], int n)
{
   int l, r, mid ;
   
   l = 0 ;
   r = n-1 ;
   while (l <= r)
   {
       mid = (l+r)/2 ;
       if ((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid] >= arr[mid+1]))
            return mid ;
            
       if (mid > 0 && arr[mid-1] > arr[mid])
            r = mid - 1 ;
       else
            l = mid + 1 ;
   }
}
