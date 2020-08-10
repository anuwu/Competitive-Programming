#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void coffee (vector<int> &A)
{
    if (!A.size())
    {
        cout << 0 << "\n" ;
        return ;
    }
    else if (A.size() == 1)
    {
        cout << A[0] << "\n" ;
        return ;
    }
    
    int i, cups, lastcup, N = A.size() ;
    
    cups = lastcup = A[N-1] ;
    for (i = N-2 ; i >= 0 ; i--)
    {
        if (A[i] < lastcup)
        {
            cups += A[i] ;
            lastcup = A[i] ;
        }
        else
        {
            if (lastcup > 0)
                lastcup-- ;
            cups += lastcup ;
        }
    }
    
    cout << cups << "\n" ;
}

int main() 
{
    int i, N ;
    vector<int> tc ;
    
    cin >> N ;
    tc = vector<int> (N, 0) ;
    for (i = 0 ; i < N ; i++)
        cin >> tc[i] ;
    
    coffee (tc) ;
    
    return 0;
}

