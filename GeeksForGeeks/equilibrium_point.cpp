#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void equilibrium (vector<int> &A)
{
    if (A.size () == 1)
    {
        cout << 1 << "\n" ;
        return ;
    }
    
    int i, j, N, suml, sumr ;
    bool crossover ;

    N = A.size() ;
    vector<int> sum (N, 0) ;
    
    crossover = false ;
    sum[0] = 0 ;
    sum[N-1] = 0 ;
    i = 1 ;
    j = N - 2 ;
    for ( ; i < N ; i++, j--)
    {
        if (i < N/2)
        {
            sum[i] = sum[i-1] + A[i-1] ;
            sum[j] = sum[j+1] + A[j+1] ;
        }
        else
        {
            if (!crossover)
            {
                crossover = true ;
                suml = sum[i-1] ;
                sumr = sum[j+1] ;
                
                if (N % 2)
                {
                    if (suml + A[i-1] == sumr + A[j+1])
                    {
                        cout << i+1 << "\n" ;
                        return ;
                    }
                    else
                    {
                        suml += A[i-1] ;
                        sumr += A[j+1] ;
                        continue ;
                    }
                }
            }
            
            if (suml + A[i-1] == sum[i])
            {
                cout << i + 1 << "\n" ;
                return ;
            }
            else
                suml += A[i-1] ;
                
            if (sumr + A[j+1] == sum[j])
            {
                cout << j + 1 << "\n" ;
                return ;
            }
            else
                sumr += A[j+1] ;
        }
    }
    
    cout << -1 << "\n" ;
}


int main() 
{
	int noTest, N, in, i, j ;
	vector<int> tc ;
	
	cin >> noTest ;
	for (i = 0 ; i < noTest ; i++)
	{
	    cin >> N ;
	    for (j = 0 ; j < N ; j++)
	    {
	        cin >> in ;
	        tc.push_back (in) ;
	    }
	    
	    equilibrium (tc) ;
	    tc.clear () ;
	}
	return 0;
}
