#include <stdio.h>

int main(void) 
{
    int x;
    while (scanf("%d",&x) > 0)
    {
        if (x != 42)
            printf ("%d\n", x) ;
        else
            break ;
    }
    
    
    
    return 0;
}
