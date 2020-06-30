int Solution::solve(vector<int> &A, int B) 
{
    int i, j, cnt, l, r, N = A.size (), M ;
    vector<int> odd ;
    
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] % 2)
            odd.push_back (i);
    }
    
    M = odd.size() ;
    if (M < B)
        return 0 ;
        
    if (B == 0)
    {
        if (M == 0)
            return (N*(N+1))/2 ;
        else
        {
            int len ;
            cnt = 0 ;
            for (i = 0 ; i < M ; i++)
            {
                if (i == 0)
                    len = odd[i] ;
                else
                    len = odd[i] - odd[i-1] - 1 ;
                    
                cnt += (len*(len+1))/2 ;
            }
            
            len = N - odd[M-1] - 1 ;
            cnt += (len*(len+1))/2 ;
        }
        
        return cnt ;
    }
        
    i = 0 ;
    cnt = 0 ;
    for (j = B-1 ; j < M ; i++, j++)
    {
        l = odd[i] + 1 ;
        if (i != 0)
            l -= odd[i-1] ;
            
        if (j == M-1)
            r = N ;
        else
            r = odd[j+1] ;
        r -= odd[j] ;
        
        cnt += l*r ;
        cout << i << " " << j << " " << cnt << "\n" ;
    }
    
    return cnt ;
}
