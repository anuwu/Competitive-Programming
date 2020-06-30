#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) 
{
    int i, height = 0, cnt = 0 ;

    for (i = 0 ; i < n ; i++)
    {
        if (s[i] == 'D')
            height-- ;
        else if (s[i] == 'U')
        {
            if (height == -1)
                cnt++ ;
            height++ ;
        }
    }

    return cnt ;
}
