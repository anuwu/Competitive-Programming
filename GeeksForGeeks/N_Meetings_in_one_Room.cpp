#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sortMeet (pair<pair<int,int>,int> &p1, pair<pair<int,int>,int> &p2)
{
    if (p1.first.second < p2.first.second)
        return 1 ;
    else if (p1.first.second > p2.first.second)
        return 0 ;
    else
    {
        if (p1.first.first < p2.first.first)
            return 1 ;
        else if (p1.first.first < p2.first.first)
            return 0 ;
        else
            return p1.second < p2.second ;
    }
}

void maxMeetings (vector<pair<pair<int,int>,int>> A)
{
    int i, lasti, mini, N = A.size() ;
    vector<int> ans ;
    sort (A.begin(), A.end(), sortMeet) ;
    
    i = 0 ;
    do
    {
        lasti = i ;
        mini = i ;
        i++ ;
        while (i < N && A[i].first.second == A[lasti].first.second)
        {
            if (A[i].second < A[mini].second)
                mini = i ;
            i++ ;
        }
        
        ans.push_back (A[mini].second) ;
        while (i < N && A[lasti].first.second >= A[i].first.first)
            i++ ;
    } while (i < N) ;
    
    for (i = 0 ; i < ans.size() ; i++)
        cout << ans[i] << " " ;
    cout << "\n" ;
}

int main() 
{
	int noTest, N, i ;
	
	cin >> noTest ;
	do
	{
	    cin >> N ;
	    vector<pair<pair<int,int>,int>> tc (N, make_pair (make_pair (0, 0), 0)) ;
	    
	    for (i = 0 ; i < N ; i++)
	    {
	        cin >> tc[i].first.first ;
	        tc[i].second = i+1 ;
	    }
	        
	    for (i = 0 ; i < N ; i++)
	        cin >> tc[i].first.second ;
	        
	    maxMeetings (tc) ;
	    tc.clear() ;
	} while (--noTest) ;
	
	return 0 ;
}
