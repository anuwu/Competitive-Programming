int Solution::removeDuplicates(vector<int> &A) 
{
    int repl, firstOcc, nextOcc, cnt = 0, N = A.size() ;
    
    repl = 0 ;
    while (repl < N - 1 && A[repl] != A[repl + 1])
        repl++ ;
    
    firstOcc = ++repl ;    
    if (repl == N || repl == N - 1)
        return repl ;
    
    do    
    {   
        cnt++ ;
        nextOcc = firstOcc + 1 ;
        while (nextOcc < N && A[nextOcc] == A[firstOcc])
        {
            cnt++ ;
            nextOcc++ ;
        }
        
        firstOcc = nextOcc ;
        while (firstOcc < N && A[firstOcc] != A[firstOcc - 1])
        {
            A[repl] = A[firstOcc] ;
            repl++ ;
            firstOcc++ ;
        }
    } while (firstOcc < N) ;
    
    return N - cnt ;
}
