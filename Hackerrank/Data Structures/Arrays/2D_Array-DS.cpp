int hourglassSum(vector<vector<int>> arr) 
{
    int i, j, maxsum = INT_MIN, sum ;
    for (i = 1 ; i <= 4 ; i++)
    {
        for (j = 1 ; j <= 4 ; j++)
        {
            sum = arr[i][j] + arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1] ;

            if (sum > maxsum)
                maxsum = sum ;
        }
    }

    return maxsum ;

}
