class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) 
    {
        int i, l, r, sum, target, N = A.size() ;
        unordered_set <int> first, second ;
        vector<int> triplet ;
        vector<vector<int>> ans ;
        
        sort (A.begin(), A.end()) ;
        
        for (i = 0 ; i < N-2 ; i++)
        {
            target = -A[i] ;
            l = i+1 ;
            r = N-1 ;
            
            if (first.find (A[i]) != first.end ())
                continue ;
            
            first.insert (A[i]) ;
            second.clear () ;
            while (l < r)
            {
                sum = A[l] + A[r] ;
                if (sum > target)
                    r-- ;
                else if (sum < target)
                    l++ ;
                else
                {
                    if (second.find (A[l]) == second.end())
                    {
                        triplet.push_back (A[i]) ;
                        triplet.push_back (A[l]) ;
                        triplet.push_back (A[r]) ;   
                        ans.push_back (triplet) ;
                        triplet.clear () ;
                        
                        second.insert (A[l]) ;
                    }
                    else
                        l++ ;
                }
            }           
        }
        
        return ans ;
    }
};
