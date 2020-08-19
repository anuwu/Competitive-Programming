class Solution {
public:
    int numJewelsInStones(string J, string S) 
    {
        unordered_set<char> jewels ;
        
        for (int i = 0 ; i < (int)J.length() ; i++)
            jewels.insert (J[i]) ;
        
        int cnt ;
        
        cnt = 0 ;
        for (int i = 0 ; i < (int)S.length() ; i++)
            if (jewels.find(S[i]) != jewels.end())
                cnt++ ;
        
        return cnt ;
    }
};
