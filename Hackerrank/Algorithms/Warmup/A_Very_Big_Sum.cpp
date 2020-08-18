long long aVeryBigSum(vector<long> ar) 
{
    int i, N = ar.size() ;
    long long sum ;

    sum = 0 ;
    for (i = 0 ; i < N ; i++)
        sum += ar[i] ;

    return sum ;
}

