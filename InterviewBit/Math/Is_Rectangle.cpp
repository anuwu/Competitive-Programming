int Solution::solve(int A, int B, int C, int D) 
{
    if (A <= 0 || B <= 0 || C <= 0 || D <= 0)
        return 0 ;
        
    unordered_map<int, int> m ;
    m[A] = 1 ;
    
    if (m.find (B) == m.end ())
        m[B] = 1 ;
    else
        m[B]++ ;
        
    if (m.find (C) == m.end ())
        m[C] = 1;
    else
        m[C]++ ;
    
    if (m.find (D) == m.end ())
        m[D] = 1 ;
    else
        m[D]++ ;

    if (m.size() != 2)
        return 0 ;
    else
    {
        for (unordered_map<int,int>::iterator it = m.begin () ; it != m.end() ; it++)
        {
            if (it->second != 2)
                return 0 ;
        }
        
        return 1 ;
    }
}
