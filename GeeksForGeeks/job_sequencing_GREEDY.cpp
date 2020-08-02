#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

int sortjob (pair<int,int> &p1, pair<int,int> &p2)
{
    if (p1.first < p2.first)
        return 1 ;
    else if (p1.first > p2.first)
        return 0 ;
    else
        return p1.second > p2.second ;
}

void jobWrong (vector<pair<int,int>> &A)
{
    int i, j, can, done, profit, N = A.size() ;
    sort (A.begin(), A.end(), sortjob) ;
    
    for (i = 0 ; i < N ; i++)
        printf ("(%d, %d)\n", A[i].first, A[i].second) ;
    
    done = profit = 0 ;
    i = 0 ;
    do
    {
        can = A[i].first - done ;
        j = i ;
        while (can-- && j < N && A[j].first == A[i].first)
        {
            done++ ;
            profit += A[j].second ;
            j++ ;
        }
        
        while (j < N && A[j].first == A[i].first)
            j++ ;
        
        i = j ;
    } while (i < N) ;
    
    printf ("%d %d\n", done, profit) ;
}

int descJob (pair<int,int> &p1, pair<int,int> &p2)
{
    return p1.second > p2.second ;
}

void job (vector<pair<int,int>> A)
{
    int i, j, done, profit, N = A.size() ;
    vector<bool> sched (N, false) ;
    
    sort (A.begin(), A.end(), descJob) ;
    profit = 0 ;
    done = 0 ;
    for (i = 0 ; i < N ; i++)
    {
        j = A[i].first - 1 ;
        while (j >= 0 && sched[j])
            j-- ;
            
        if (j != -1)
        {
            profit += A[i].second ;
            done++ ;
            sched[j] = true ;
        }
    }
    
    printf ("%d %d\n", done, profit) ;
}

int main() 
{
	int noTest, N, in, i ;
	
	cin >> noTest ;
	do
	{
	    cin >> N ;
	    vector<pair<int,int>> tc (N, make_pair (0, 0)) ;        // (deadline, profit)
	    
	    for (i = 0 ; i < N ; i++)
	        cin >> in >> tc[i].first >> tc[i].second ;
	        
	    job (tc) ;
	    tc.clear () ;
	} while (--noTest) ;
	
	return 0;
}
