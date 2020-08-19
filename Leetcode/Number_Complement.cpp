class Solution {
public:
    int findComplement(int num) 
    {
        int i, lim, mask ;
        
        for (lim = 31 ; lim >= 0 ; lim--)
            if ((num >> lim) & 1)
                break ;
        
        //printf ("%d\n", lim) ;
        mask = 0 ;
        for (i = 0 ; i <= lim ; i++)
            mask |= 1 << i ;
        
        return mask ^ num ;
    }
};
