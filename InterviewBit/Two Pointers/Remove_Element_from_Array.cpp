int Solution::removeElement(vector<int> &A, int B) 
{
    int repl, occs, non ;
    
    repl = 0 ;
    while (repl < A.size () && A[repl] != B)
        repl++ ;
        
    if (repl == A.size ())
        return repl ;
        
    occs = 1 ;
    non = repl + 1 ;
    while (true)
    {
        while (non < A.size () && A[non] == B)
        {
            occs++ ;
            non++ ;
        }
            
        if (non == A.size ())
            return non - occs ;
            
        A[repl] = A[non] ;
        repl++ ;
        non++ ;
    }
}
