
unordered_map<int,vector<int>> children ;

int diam (int root, int *h)
{
    if (children[root].size() == 0)
    {
        *h = 1 ;
        return 0 ;
    }
    
    int i, height, maxh1, maxh2, maxdiam, dia ;
    
    maxdiam = maxh1 = maxh2 = 0 ;
    for (i = 0 ; i < children[root].size() ; i++)
    {
        height = 0 ;
        dia = diam (children[root][i], &height) ;
        
        if (dia > maxdiam)
            maxdiam = dia ;
        
        if (height > maxh1)
        {
            maxh2 = maxh1 ;
            maxh1 = height ;
        }
        else if (height > maxh2)
            maxh2 = height ;
    }

    *h = maxh1 + 1 ;
    return max (maxh1 + maxh2, maxdiam) ;
}


int Solution::solve(vector<int> &A) 
{
    children.clear () ;
    
    int i, h, root, N = A.size() ;
    vector<int> emp ;
    
    for (i = 0 ; i < N ; i++)
        children[i] = emp ;
    
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] == -1)
            root = i ;
        else
            children[A[i]].push_back(i) ; 
    }
    
    return diam (root, &h) ;
}

