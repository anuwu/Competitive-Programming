void staircase(int n) 
{
    int i, j ;

    for (i = 1 ; i <= n ; i++)
    {
        for (j = 1 ; j <= n-i ; j++)
            printf (" ") ;
        for ( ; j <= n ; j++)
            printf ("#") ;
        printf ("\n") ;
    }
}

