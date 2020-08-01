
void distributeSpaces (int spaces, int slots, vector<int> &spcDist)
{
    spcDist.clear () ;
    
    if (!slots)
        return ;
    
    if (spaces % slots == 0)
        spcDist = vector<int> (slots, spaces/slots) ;
    else
    {
        int large = spaces/slots + 1 ;
        while (spaces % slots)
        {
            spcDist.push_back (large) ;
            slots-- ;
            spaces -= large ;
        }
        
        spcDist.insert (spcDist.end(), slots, spaces/slots) ;
    }
}


vector<string> Solution::fullJustify(vector<string> &A, int L) 
{
    int i, j, k, linetext, spaces, words = A.size() ;
    vector<string> ans ;
    vector<int> spcDist ;
    string str ;
    
    if (A.size() == 0)
        return ans ;
    
    i = 0 ;
    do
    {
        linetext = -1 ;
        j = i - 1 ;
        do
        {
            j++ ;
            if (j == words)
                break ;
            
            linetext += A[j].length () ;
            linetext++ ;
        } while (linetext <= L) ;
    
        spaces = 0 ;
        if (linetext > L)
        {
            linetext -= A[j].length() ;
            linetext -= (j-i) ;
            j-- ;
            
            spaces = L - linetext ;
            distributeSpaces (spaces, j - i, spcDist) ;
            str = string (A[i]) ;
        }
        else if (j == words || linetext == L)
        {
            if (j == words)
                j-- ;
            
            spcDist = vector<int> (j - i, 1) ;
            str = string (A[i]) ;
        }
        
        for (k = 0 ; k < spcDist.size() ; k++)
        {
            str.append (string (spcDist[k], ' ')) ;
            str.append (A[i+k+1]) ;
        }   
        
        if (j + 1 == words || !spcDist.size()) 
            str.append (string (L - linetext, ' ')) ;
        
        ans.push_back (str) ;
        i = j+1 ;
    } while (i < words) ;
    
    return ans ;
}
