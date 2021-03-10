class Solution {
public:
    void merge (vector<int> &A, int l1, int r1, int l2, int r2, unordered_map<int,int> &mp, vector<int> &sm)
    {
        int i, j, k, cnt = 0, mg_size ;
        mg_size = r2-l1+1 ;
        vector<int> mg_arr (mg_size, 0) ;
        vector<int> mg_mp (mg_size, 0) ;
        
        i = l1 ; j = l2 ; k = 0 ;
        for (k = 0 ; i <= r1 && j <= r2 ; k++)
        {
            if (A[i] <= A[j])
            {
                mg_arr[k] = A[i] ;
                mg_mp[k] = i ;
                sm[mp[i]] += j - l2 ;
                i++ ;
            }
            else
            {        
                mg_arr[k] = A[j] ;
                mg_mp[k] = j ;
                j++ ;
            }
        }
        
        if (i > r1)
        {
            for ( ; j <= r2 ; j++, k++)
            {
                mg_arr[k] = A[j] ;
                mg_mp[k] = j ;
            }
        }
        
        if (j > r2)
        {
            for ( ; i <= r1 ; i++, k++)
            {
                mg_arr[k] = A[i] ;
                mg_mp[k] = i ;
                sm[mp[i]] += j-l2 ;
            }
        }
        
        for (k = 0 ; k < mg_size ; k++)
            mg_mp[k] = mp[mg_mp[k]] ;
        
        for (k = 0 ; k < mg_size ; k++)
        {
            A[l1+k] = mg_arr[k] ;
            mp[l1+k] = mg_mp[k] ;
        }
    }
    
    void mergesort(vector<int> &A, int l, int r, unordered_map<int,int> &mp, vector<int> &sm)
    {   
        if (r > l)
        {
            int mid = (l+r)/2 ;
            mergesort(A, l, mid, mp, sm) ;
            mergesort(A, mid+1, r, mp, sm) ;
            merge(A, l, mid, mid+1, r, mp, sm) ;
        }
    }
    
    vector<int> countSmaller(vector<int>& nums)
    {
        int i, N = nums.size() ;
        unordered_map<int,int> mp ;
        vector<int> sm(N, 0) ;
        
        for (i = 0 ; i < N ; i++)
            mp[i] = i ;
        
        mergesort(nums, 0, N-1, mp, sm) ;
        return sm ;
    }
};
