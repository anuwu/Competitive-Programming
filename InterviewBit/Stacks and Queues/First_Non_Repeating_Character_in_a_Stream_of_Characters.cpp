    back = 0 ;
    ans.push_back (A[0]) ;
    m[A[0]] = 1 ;
    for (fwd = 1 ; fwd < L ; fwd++)
    {
        if (m.find (A[fwd]) == m.end())
            m[A[fwd]] = 1 ;
        else
            m[A[fwd]]++ ;
        
        if (A[fwd] == A[back])
        {
            while (back <= fwd)
            {
                if (m[A[back]] == 1)
                    break ;
                back++ ;
            }
            
            if (back > fwd)
                ans.push_back ('#') ;
            else
                ans.push_back (A[back]) ;
        }
        else
            ans.push_back (A[back]) ;
    }
    
    return ans ;
}
