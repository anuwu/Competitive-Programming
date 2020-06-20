/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
 
int isVowel (char c)
{
if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    return 1 ;
    
return 0 ;
}


int solve(char* A) 
{
    int i, cnt = 0, sum = 0 ;
    
    for (i = 0 ; A[i] != '\0' ; i++)
    {
        if (isVowel (A[i]))
        {
            cnt++ ;
            sum -= i ;
        }
    }
    
    sum += cnt*i ;
    return sum ;
}
