int Solution::isValidSudoku(const vector<string> &A) 
{
    int i, j, boxno, N = 9 ;
    unordered_set<char> rows[9] ;
    unordered_set<char> cols[9] ;
    unordered_set<char> boxes[9] ;
    
    for (i = 0 ; i < N ; i++)
    {
        for (j = 0 ; j < N ; j++)
        {
            if (A[i][j] != '.')
            {
                if (rows[i].find (A[i][j]) != rows[i].end())
                    return 0 ;
                rows[i].insert (A[i][j]) ;
                
                if (cols[j].find (A[i][j]) != cols[j].end())
                    return 0 ;
                cols[j].insert (A[i][j]) ;
                
                boxno = 3*(i/3) + (j/3) ;
                if (boxes[boxno].find (A[i][j]) != boxes[boxno].end())
                    return 0 ;
                boxes[boxno].insert (A[i][j]) ;
            }
        }
    }
    
    return 1 ;
}

