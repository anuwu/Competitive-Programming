#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;


void firstMissPos (vector<int> &A)
{
    if (!A.size())
    {
        cout << 0 << "\n" ;
        return ;
    }
    
    int i, ind, miss, N = A.size() ;
    
    for (i = 0 ; i < N ; i++)
    {
        if (A[i] > 0)
            ind = A[i] - 1 ;
        else
            ind = -A[i] - 1 ;
        
        if (0 <= ind && ind < N && A[ind] > 0)
            A[ind] *= -1 ;
    }
    
    miss = N + 1 ;
    for (i = 0 ; i < N ; i++)
        if (A[i] > 0)
        {
            miss = i + 1 ;
            break ;
        }
    
    miss-- ;
    cout << miss << "\n" ;
}

int main() 
{
    int i, in, N, M, D ;
    vector<int> pot, A ;
    unordered_map<int,set<pair<int,int>>> assoc ;
    unordered_map<int,int> stud ;
    set<pair<int,int>> emp ;
    set<pair<int,int>>::iterator itr ;
    
    cin >> N >> M ;
    pot = vector<int> (N, 0) ;
    
    for (i = 0 ; i < N ; i++)
        cin >> pot[i] ;
    
    emp.clear () ;
    for (i = 0 ; i < N ; i++)
    {
        cin >> in ;
        in-- ;

        stud[i] = in ;
        if (assoc.find (in) == assoc.end())
            assoc[in] = emp ;
        assoc[in].insert (make_pair (pot[i], i)) ;
    }
        
    cin >> D ;
    for (i = 0 ; i < D ; i++)
    {
        cin >> in ;
        in-- ;
        
        itr = assoc[stud[in]].find (make_pair (pot[in], in)) ;        
        assoc[stud[in]].erase (itr) ;
        stud.erase (stud.find (in)) ;
        
        A.clear () ;
        for (auto it = assoc.begin() ; it != assoc.end() ; it++)
            if (it->second.size())
                A.push_back ((it->second).begin()->first + 1) ;
        
        //cout << "\n" ;
        firstMissPos (A) ;
    }
    
    
    return 0;
}
