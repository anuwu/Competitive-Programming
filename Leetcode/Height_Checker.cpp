class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        int i, cnt ;
        vector<int> sorted (heights) ;
        
        sort (sorted.begin(), sorted.end()) ;
        cnt = 0 ;
        for (i = 0 ; i < (int)heights.size() ; i++)
            if (heights[i] != sorted[i])
                cnt++ ;
        
        return cnt ;
    }
};
