#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> A) 
{
    int i, pairs ;
    unordered_map<int,int> m ;
    unordered_map<int,int>::iterator it ;

    for (i = 0 ; i < n ; i++)
    {
        if (m.find(A[i]) == m.end())
            m[A[i]] = 1 ;
        else
            m[A[i]]++ ;
    }
    
    pairs = 0 ;
    for (it = m.begin() ; it != m.end() ; it++)
        pairs += it->second/2 ;

    return pairs ;
}
