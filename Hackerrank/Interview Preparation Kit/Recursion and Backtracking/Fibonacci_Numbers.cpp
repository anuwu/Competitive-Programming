int fibonacci(int n) 
{
    if (n == 1)
        return 1 ;

    int lastone, lasttwo, i, curr ;

    lastone = 1 ;
    lasttwo = 0 ;
    for (i = 2 ; i <= n ; i++)
    {
        curr = lastone + lasttwo ;
        lasttwo = lastone ;
        lastone = curr ;
    }    

    return curr ;
}
