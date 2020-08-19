class Solution {
public:
    int maximum69Number (int num) 
    {
        int addplc, plc, dig, save ;
        
        addplc = -1 ;
        plc = 0 ;
        save = num ;
        while (save)
        {
            dig = save % 10 ;
            if (dig == 6)
                addplc = plc ;
            save /= 10 ;
            plc++ ;
        }
        
        
        return (addplc == -1) ? num : num + (int)pow(10, addplc)*3 ;
        
    }
};
