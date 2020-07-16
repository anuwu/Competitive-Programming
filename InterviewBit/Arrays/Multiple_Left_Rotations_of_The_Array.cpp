vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) 
{
    int i, j, k, ind, tmp1, tmp2, lim, N = A.size() ;
    vector<vector<int>> ans ;
    vector<int> row ;
    
    for (i = 0 ; i < B.size() ; i++)
    {
        k = B[i] % N ;
        lim = __gcd (N, k) ;
        row = vector<int> (A) ;
        
        for (j = N-1 ; j >= N - lim ; j--)
        {
            ind = j ;
            tmp1 = row[ind] ;
            ind -= k ;
            do
            {
                tmp2 = tmp1 ;
                tmp1 = row[ind] ;
                row[ind] = tmp2 ;
                
                ind -= k ;
                if (ind < 0)
                    ind += N ;
            } while (ind != j) ;
            
            row[j] = tmp1 ;
        }

        
        ans.push_back (row) ;
    }
    

    return ans ;
}

