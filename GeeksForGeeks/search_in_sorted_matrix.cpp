#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void searchMat (vector<vector<int>> A, int target)
{
    int N = A.size(), M = A[0].size() ;
    int colLo, colHi, colMid, col, lastCol ;
    int rowLo, rowHi, rowMid ;
    
    lastCol = -1 ;
    colLo = 0 ;
    colHi = M-1 ;
    while (colLo <= colHi)
    {
        colMid = colLo + (colHi - colLo)/2 ;
        if (target < A[0][colMid])
            colHi = colMid - 1 ;
        else if (A[0][colMid] <= target && target <= A[N-1][colMid])
        {
            if (A[0][colMid] == target || A[N-1][colMid] == target)
            {
                cout << 1 << "\n" ;
                return ;
            }
            
            lastCol = colMid ;
            colLo = colMid + 1 ;
        }
        else
            colLo = colMid + 1 ;
    }
    
    if (lastCol == -1)
    {
        cout << 0 << "\n" ;
        return ;
    }
    
    col = lastCol - 1 ;
    while (col >= 0 && target <= A[N-1][col])
    {
        if (target == A[N-1][col])
        {
            cout << 1 << "\n" ;
            return ;
        }
        
        col-- ;
    }
    
    do
    {
        col++ ;
        rowLo = 0 ;
        rowHi = N-1 ;
        while (rowLo <= rowHi)
        {
            rowMid = rowLo + (rowHi - rowLo)/2 ;
            if (A[rowMid][col] == target)
            {
                cout << 1 << "\n" ;
                return ;
            }
            else if (target < A[rowMid][col])
                rowHi = rowMid - 1 ;
            else
                rowLo = rowMid + 1 ;
        }
        
    } while (col <= lastCol) ;
    
    
    cout << 0 << "\n" ;
}

int main() 
{
	int noTest, N, M, target, i, j ;
	
	cin >> noTest ;
	do
	{
	    cin >> N >> M ;
	    vector<vector<int>> tc (N, vector<int> (M, 0)) ;
	    
	    for (i = 0 ; i < N ; i++)
	        for (j = 0 ; j < M ; j++)
	            cin >> tc[i][j] ;
	    
	    cin >> target ;
	    searchMat (tc, target) ;
	    tc.clear() ;
	} while (--noTest) ;
	
	return 0;
}sww
