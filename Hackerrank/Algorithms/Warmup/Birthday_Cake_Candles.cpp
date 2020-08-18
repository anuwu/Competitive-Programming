int birthdayCakeCandles(vector<int> A) 
{
    int i, cnt, maxe ;

    cnt = 1 ;
    maxe = A[0] ;
    for (i = 1 ; i < (int)A.size() ; i++)
    {
        if (A[i] == maxe)
            cnt++ ;
        else if (A[i] > maxe)
        {
            maxe = A[i] ;
            cnt = 1 ;
        }
    }

    return cnt ;
}
