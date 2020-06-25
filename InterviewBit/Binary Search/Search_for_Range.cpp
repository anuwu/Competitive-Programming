vector<int> Solution::searchRange(const vector<int> &A, int B) 
{
    int l, r, firstOcc, leftOcc, rightOcc ;
    vector<int> ans ;
    
    l = 0 ;
    r = A.size () - 1 ;
    while (l <= r)
    {
        firstOcc = (l + r)/2 ;
        if (B < A[firstOcc])
            r = firstOcc - 1 ;
        else if (B > A[firstOcc])
            l = firstOcc + 1 ;
        else
            break ;
    }
    
    if (l > r)
    {
        ans.push_back (-1) ;
        ans.push_back (-1) ;
        return ans ;
    }
    
    l = 0 ;
    r = firstOcc - 1 ;
    while (l <= r)
    {
        leftOcc = (l + r)/2 ;
        if (A[leftOcc] == B)
            r = leftOcc - 1 ;
        else
            l = leftOcc + 1 ;
        
    }
    leftOcc = l ;
    
    l = firstOcc + 1 ;
    r = A.size () - 1 ;
    while (l <= r)
    {
        rightOcc = (l + r)/2 ;
        if (A[rightOcc] == B)
            l = rightOcc + 1 ;
        else
            r = rightOcc - 1 ;
    }
    rightOcc = r ;
    
    ans.push_back (leftOcc) ;
    ans.push_back (rightOcc) ;
    
    return ans ;
}

