int Solution::solve(int E, int F) 
{
    if (E == 1)
        return F ;
    
    int e, t ;
    vector<vector<int>> egg (E+1, vector<int> (F+1, 0)) ;
    
    for (t = 1 ; t <= F ; t++)
        egg[1][t] = t ;
    
    for (e = 1 ; e <= E ; e++)
        egg[e][1] = 1 ;
        
    for (e = 2 ; e <= E ; e++)
    {
        t = 1 ;
        do
        {
            egg[e][t] = egg[e-1][t-1] + egg[e][t-1] + 1 ;
            if (egg[e][t] >= F)
                break ;
                
            t++ ;
        } while (t <= F) ;
    }
    
    return t ;
}

