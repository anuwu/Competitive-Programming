int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) 
{
    // R1 - (A, B) and (C, D)
    // R2 - (E, F) and (G, H)
    
    int xdiff, ydiff ;
    
    xdiff = E-A ;
    ydiff = F-B ;
    if (xdiff == 0 || (double)ydiff/xdiff > 0)
    {
        /*
        // 
        //      (E, F)                            (E, F)
        //         ^                             /^
        //         |            or              /
        //         v                          v/
        //      (A, B)                  (A, B)
        //
        //
        //
        */
        
        if (E > A)
        {
            int r1A, r1B, r1C, r1D, r2A, r2B, r2C, r2D ;
            r1A = A ;
            r1B = B ;
            r1C = C ;
            r1D = D ;
            r2A = E ;
            r2B = F ;
            r2C = G ;
            r2D = H ;
        }
        else
        {
            r1A = E ;
            r1B = F ;
            r1C = G ;
            r1D = H ;
            r2A = A ;
            r2B = B ;
            r2C = C ;
            r2D = D ;
        }
        
        /*
        // 
        //      (r2A, r2B)                        (r2A, r2B)
        //         ^                             /^
        //         |            or              /
        //         v                          v/
        //      (r1A, r1B)                  (r1A, r1B)
        //
        //
        //
        */
        
        
        
        
    }
    else // xdiff != 0 && ydiff/xdiff <= 0
    {
        if (ydiff == 0)
        {
            
        }
        
        // xdiff != 0 && ydiff/xdiff < 0
    }
}

