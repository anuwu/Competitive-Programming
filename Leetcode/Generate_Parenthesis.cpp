class Solution {
public:
    
    void backtrack (int open, int close, int n, string str, vector<string> &ans)
    {
        if (close == n)
        {
            ans.push_back (str) ;
            return ;
        }
        
        string s ;
        if (open < n)
        {
            s = string (str) ;
            s.push_back ('(') ;
            backtrack (open + 1, close, n, s, ans) ;
        }
        if (close < open)
        {
            s = string (str) ;
            s.push_back (')') ;
            backtrack (open, close + 1, n, s, ans) ;
        }
    }
    
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans ;
        string str ;
        
        backtrack (0, 0, n, str, ans) ;
        return ans ;
    }
};
