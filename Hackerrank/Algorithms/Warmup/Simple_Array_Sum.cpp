int simpleArraySum(vector<int> A) 
{
    int i, sum, N = A.size() ;

    sum = 0 ;
    for (i = 0 ; i < N ; i++)
        sum += A[i] ;

    return sum ;
}
