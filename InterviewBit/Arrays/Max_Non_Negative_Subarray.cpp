vector<int> Solution::maxset(vector<int> &A) 
{
    int i, maxlength, sti, mini, ansi, anslength ;
    long long maxsum, sum ;
    vector<int> ans ;
    
    maxsum = INT_MIN ;
    maxlength = INT_MIN ;
    mini = A.size () ;
    i = 0 ;
    do
    {
        while (i < A.size () && A[i] < 0)
            i++ ;
        
        if (i == A.size ())
            break ;
            
        sum = 0 ;
        sti = i ;
        while (i < A.size () && A[i] >= 0)
        {
            sum += A[i] ;
            i++ ;
        }
            
        if (sum > maxsum)
        {
            maxsum = sum ;
            ansi = sti ;
            anslength = i - sti ;
            
            
            if (maxlength == INT_MIN)
                maxlength = anslength ;
            if (mini == A.size ())
                mini = ansi ;
        }
        else if (sum == maxsum)
        {
            if (i - sti > maxlength)
            {
                maxlength = i - sti ;
                anslength = maxlength ;
                ansi = sti ;
            }
            else if (i - sti == maxlength)
            {
                if (sti < mini)
                {
                    mini = sti ;
                    ansi = sti ;
                }
            }
        }
    } while (true) ;
    
    
    if (mini != A.size ())
    {
        for (i = ansi ; i < ansi + anslength ; i++)
            ans.push_back (A[i]) ;
    }
    
    return ans ;
}

