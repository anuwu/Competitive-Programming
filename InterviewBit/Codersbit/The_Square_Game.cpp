int Solution::solve(int A, int B, int C, int D) 
{
    if (B == D)
        return 0 ;
        
    int r, c ;
    
    r = C - A - 1 ;
    c = D - B - 1 ;
    
    return r*c ;
}

