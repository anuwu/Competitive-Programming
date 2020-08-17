int minimumAbsoluteDifference(vector<int> arr) 
{
    int i, mindiff, N = arr.size() ;
    sort (arr.begin(), arr.end()) ;

    mindiff = INT_MAX ;
    for (i = 1 ; i < N ; i++)
        if (arr[i] - arr[i-1] < mindiff)
            mindiff = arr[i] - arr[i-1] ;

    return mindiff; 
}
