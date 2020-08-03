#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

int descJob (pair<int,int> &p1, pair<int,int> &p2)
{
    return p1.second > p2.second ;
}


int find (int x, vector<pair<int,int>> &ds)
{
    if (ds[x].first != x)
        ds[x].first = find (ds[x].first, ds) ;
        
    return ds[x].first ;
}

void dsUnion (int p1, int p2, vector<pair<int,int>> &ds)
{
    if (ds[p1].second < ds[p2].second)
    {
        if (p1 < p2)
        {
            ds[p2].first = p1 ;
            ds[p1].second = ds[p2].second + 1 ;
        }
        else
            ds[p1].first = p2 ;
    }
    else if (ds[p2].second < ds[p1].second)
    {
        if (p2 < p1)
        {
            ds[p1].first = p2 ;
            ds[p2].second = ds[p1].second + 1 ;
        }
        else
            ds[p2].first = p1 ;
    }
    else
    {
        if (p2 < p1)
        {
            ds[p1].first = p2 ;
            ds[p2].second++ ;
        }
        else
        {
            ds[p2].first = p1 ;
            ds[p1].second++ ;
        }
    }
}

void job (vector<pair<int,int>> &A)
{
    if (!A.size())
    {
        printf ("0 0\n") ;
        return ;
    }
    else if (A.size() == 1)
    {
        printf ("1 %d\n", A[0].second) ;
        return ;
    }
    
    int deadmax, done, profit, freeslot, i, N = A.size() ;
    
    deadmax = A[0].first ;
    for (i = 1 ; i < N ; i++)
        if (A[i].first > deadmax)
            deadmax = A[i].first ;
            
    vector<pair<int,int>> ds (deadmax, make_pair (0, 0)) ;
    for (i = 0 ; i <= deadmax ; i++)
        ds[i].first = i ;
        
    sort (A.begin(), A.end(), descJob) ;
    
    done = 0 ;
    profit = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        freeslot = find (A[i].first, ds) ;
        if (freeslot)
        {
            done++ ;
            profit += A[i].second ;
            dsUnion (find(freeslot - 1, ds), freeslot, ds) ;
        }
    }
    
    printf ("%d %d\n", done, profit) ;
}

int main() 
{
	int noTest, N, in, i ;
	
	cin >> noTest ;
	while (noTest--)
	{
	    cin >> N ;
	    vector<pair<int,int>> tc (N, make_pair (0, 0)) ;        // (deadline, profit)
	    
	    for (i = 0 ; i < N ; i++)
	        cin >> in >> tc[i].first >> tc[i].second ;
	        
	    job (tc) ;
	    tc.clear () ;
	}
	
	return 0;
}