class Solution {
public:
    int balancedStringSplit(string s) 
    {
        int bal, cnt = 0 ;
        
        if (s[0] == 'R')
            bal = 1 ;
        else
            bal = -1 ;
        
        cnt = 0 ;
        for (int i = 1 ; i < s.length() ; i++)
        {
            if (s[i] == 'R')
                bal++ ;
            else
                bal-- ;
            
            if (!bal)
                cnt++ ;
        }
        
        return cnt ;
        
    }
};
