#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std ;

int power(string A) 
{
    if (!A.compare("2") || !A.compare("4") || !A.compare("8") || !A.compare("16") || 
        !A.compare("32") || !A.compare("64") || !A.compare("128") || !A.compare("256") || !A.compare("512"))
        return 1 ;
    
    int i, len, carry, dvdnd, quodig, rep ;
    char ch ;
    string num (A), quo ("") ;
    
    num = A ;
    do
    {
        len = num.length () ;
        
        if (len == 1 && num[0] != '8')
		    return 0 ;
        
        if (num[0] < '8')
            carry = (int)(num[0] - '0') ;
        else
        {
            quo.push_back ('1') ;
            carry = num[0] - '8' ;
        }
        
        for (i = 1 ; i < len - 1 ; i++)
        {
            if (carry)
            {
                dvdnd = carry*10 + (int)(num[i] - '0') ;
                quodig = dvdnd/8 ;
                carry = dvdnd % 8 ;
                ch = (char)((int)'0' + quodig) ;
                quo.push_back (ch) ;
            }
            else
            {
                if (num[i] < '8')
		{
		    quo.push_back ('0') ;
                    carry = (int)(num[i] - '0') ;
		}
                else
                {
                    quo.push_back ('1') ;
                    carry = num[i] - '8' ;
                }
            }
        }
        
        if (carry)
        {
            dvdnd = carry*10 + (int)(num[i] - '0') ;
            quodig = dvdnd/8 ;
            carry = dvdnd % 8 ;
            if (carry)
                return 0 ;
                
            ch = (char)((int)'0' + quodig) ;
            quo.push_back (ch) ;
        }
        else
        {
            if (num[i] != '8')
                return 0 ;
            quo.push_back ('1') ;
        }
        
	if (!quo.compare("2") || !quo.compare("4") || !quo.compare("8") || !quo.compare("16") || 
        !quo.compare("32") || !quo.compare("64") || !quo.compare("128") || !quo.compare("256") || !quo.compare("512"))
            return 1 ;

	num = string (quo) ;	    	
	quo.clear () ;
    } while (true) ;
    
        
    return 1 ;
}


int main (int argc, char **argv)
{
	cout << "Answer = " << power (string(argv[1])) << "\n" ;
	return 0 ;
}
