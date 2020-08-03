#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) 
{
    int i, sum, l = s.length() ;
    vector<int> pref (l, 0) ;

    sum = 0 ;
    for (i = 0 ; i < l ; i++)
    {
        if (s[i] == 'a')
            sum += 1 ;
        pref[i] = sum ;
    }

    return n/l * pref[l-1] + (n % l ? pref[n % l - 1] : 0) ;
}
