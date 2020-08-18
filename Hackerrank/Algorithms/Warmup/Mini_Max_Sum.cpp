void miniMaxSum(vector<int> A) 
{
    int i, minele, maxele ;
    long long sum, sum1, sum2 ;

    sum = minele = maxele = A[0] ;
    for (i = 1 ; i < (int)A.size() ; i++)
    {
        sum += A[i] ;
        if (A[i] < minele)
            minele = A[i] ;
        if (A[i] > maxele)
            maxele = A[i] ;
    }

    sum1 = sum - maxele ;
    sum2 = sum - minele ;
    cout << sum1 << " " << sum2 << "\n" ;
}
