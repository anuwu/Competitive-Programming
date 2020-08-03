vector<int> compareTriplets(vector<int> A, vector<int> B) 
{
    int i, alice, bob, N = A.size() ;
    vector<int> ans ;

    alice = bob = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] > B[i])
            alice++ ;
        else if (A[i] < B[i])
            bob++ ;
    }

    ans.push_back (alice) ;
    ans.push_back (bob) ;
    return ans ;
}
