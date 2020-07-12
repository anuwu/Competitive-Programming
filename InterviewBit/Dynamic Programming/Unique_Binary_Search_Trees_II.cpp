int Solution::numTrees(int A) 
{
    if (A == 0 || A == 1)
        return 1 ;
    
    int i, j ;
    vector<int> catalan (A+1, 0) ;
    
    catalan[0] = 1 ;
    catalan[1] = 1 ;
    for (i = 2 ; i <= A ; i++)
    {
        for (j = i-1 ; j >= (i+1)/2 ; j--)
            catalan[i] += catalan[j] * catalan[i-j-1] ;
        
        catalan[i] *= 2 ;
        if (i % 2)
            catalan[i] += catalan[i/2] * catalan[i/2] ;
    }
    
    return catalan[A] ;
}

