vector<vector<int> > Solution::fourSum(vector<int> &A, int B) 
{
    int i, j, l, r, sum, tar, N = A.size() ;
    vector<int> quad ;
    vector<vector<int>> ans ;
    unordered_set<int> first, second, third ;
    
    sort (A.begin(), A.end()) ;
    
    for (i = 0 ; i < N - 3 ; i++)
    {
        if (first.find (A[i]) != first.end ())
            continue ;
        first.insert (A[i]) ;
        
        second.clear () ;
        for (j = i+1 ; j < N - 2 ; j++)
        {
            if (second.find (A[j]) != second.end())
                continue ;
            second.insert (A[j]) ;    
            
            tar = B - (A[i] + A[j]) ;
            l = j+1 ;
            r = N-1 ;
            third.clear () ;
            while (l < r)
            {
                sum = A[l] + A[r] ;
                if (sum < tar)
                    l++ ;
                else if (sum > tar)
                    r-- ;
                else
                {
                    if (third.find (A[l]) == third.end())
                    {
                        quad.push_back (A[i]) ;
                        quad.push_back (A[j]) ;
                        quad.push_back (A[l]) ;
                        quad.push_back (A[r]) ;
                        ans.push_back (quad) ;
                        
                        quad.clear () ;
                        third.insert (A[l]) ;
                    }
                    else
                        l++ ;
                }
            }
        }
    }
    
    return ans ;

}

