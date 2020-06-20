int Solution::bulbs(vector<int> &A) 
{
    int noswitch, i ;
    
    noswitch = 0 ;
    for (i = 0 ; i < A.size() ; i++)
    {
        if (!((noswitch % 2) ^ A[i]))
            noswitch++ ;
    }
    
    return noswitch ;
}

