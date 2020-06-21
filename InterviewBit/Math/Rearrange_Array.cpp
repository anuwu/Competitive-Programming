void Solution::arrange(vector<int> &A) 
{
    int i, n = A.size () ;
    int cycstart, savestart, c, nextc, zeroindex ;
    
    cycstart = 0 ;
    do
    {
        savestart = A[cycstart] ; 
        c = cycstart ; 
        nextc = A[c] ;
        while (nextc != cycstart)
        {
            if (A[c] == 0)
                zeroindex = c ;
    
            A[c] = A[c]*n + A[nextc] ;
            c = nextc ;
            nextc = A[c] ;
        }
        if (A[c] == 0)
            zeroindex = c ;
        A[c] = A[c]*n + savestart ;

        do cycstart++ ; while (cycstart < n && ((cycstart == zeroindex && A[zeroindex]) || A[cycstart] >= n));
    } while (cycstart < n) ;
    
    for (i = 0 ; i < n ; i++)
        A[i] %= n ;
}
