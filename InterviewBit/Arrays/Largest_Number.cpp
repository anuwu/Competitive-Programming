int lower (int n1, int n2)
{
    string s1, s2 ;
    s1 = to_string (n1) ;
    s2 = to_string (n2) ;
    
    if (s1.length() == s2.length ())
        return n1 < n2 ;
    else if (s1.length() < s2.length())
    {
        int i, j ;
        for (i = 0 ; i < s1.length() ; i++)
        {
            if (s1[i] < s2[i])
                return 1 ;
            else if (s1[i] > s2[i])
                return 0 ;
        }
        
        j = 0 ;
        while (true)
        {
            if (s2[i] > s1[j % s1.length()])
                return 1 ;
            else if (s2[i] < s1[j % s1.length()])
                return 0 ;
            
            i++ ;
            j++ ;
            if (i == s2.length())
                break ;
        }
        
        if (j % s1.length() == 0)
            return 0 ; 
        else
        {
            int l, k ;
            
            l = 0 ;
            k = s2.length () - s1.length () ;
            
            while (l < s1.length () && s1[l] == s2[k])
            {
                l++ ;
                k++ ;
            }
            
            if (l == s1.length ())
                return 1 ;
                
            if (s2[k] > s1[l])
                return 0 ;
            else
                return 1 ;
        }
    }
    else
    {
        int i, j ;
        for (i = 0 ; i < s2.length() ; i++)
        {
            if (s2[i] < s1[i])
                return 0 ;
            else if (s2[i] > s1[i])
                return 1 ;
        }
        
        j = 0 ;
        while (true)
        {
            if (s1[i] > s2[j % s2.length()])
                return 0 ;
            else if (s1[i] < s2[j % s2.length()])
                return 1 ;
            
            i++ ;
            j++ ;
            if (i >= s1.length())
                break ;
        }
        
        if (j % s2.length() == 0)
            return 1 ; 
        else
        {
            int l, k ;
            
            l = 0 ;
            k = s1.length () - s2.length () ;
            
            while (l < s2.length () && s2[l] == s1[k])
            {
                l++ ;
                k++ ;
            }
            
            if (l == s2.length ())
                return 0 ;
                
            if (s1[k] > s2[l])
                return 1 ;
            else
                return 0 ;
        }
    }
}

string Solution::largestNumber(const vector<int> &A) 
{
    int i, trail ;
    string ans, numstr ;
    vector<int> B = A ;
    sort (B.begin(), B.end(), lower) ;
    
    
    for (trail = 0 ; trail < B.size () && B[trail] == 0 ; trail++) ;
    
    if (trail == B.size ())
    {
        ans = to_string (0) ;
        return ans ;
    }

    for (i = B.size() - 1 ; i >= trail ; i--)
    {
        numstr = to_string (B[i]) ;
        ans.append (numstr) ;
    }
    
    return ans ;
}
