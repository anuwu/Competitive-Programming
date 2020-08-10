#include <iostream>

using namespace std ;

void partition (vector<int> &A)
{
	
}

int main ()
{
	int i, N ;
	vector<int> tc ;

	cin >> N ;
	tc = vector<int> (N, 0) ;
	for (i = 0 ; i < N ; i++)
		cin >> tc[i] ;

	partition (tc) ;
}