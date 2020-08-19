#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

#define pb push_back
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define mp make_pair
#define um unordered_map


int main ()
{
	int i, l, oddcnt ;
	char oddch ;
	string str, save = "", ans = "" ;
 	um<char,int> m ;

	cin >> str ;
	l = str.length () ;
	if (l == 1)
	{
		cout << str << "\n" ;
		return 0 ;
	}

	for (i = 0 ; i < l ; i++)
		if (m.find (str[i]) == m.end())
			m[str[i]] = 1 ;
		else
			m[str[i]]++ ;

	oddcnt = 0 ;
	for (auto it = m.begin() ; it != m.end() ; it++)
	{
		if (it->second % 2)
		{
			oddcnt++ ;
			if (oddcnt > 1)
			{
				cout << "NO SOLUTION" << "\n" ;
				return 0 ;
			}

			oddch = it->first ;
			it->second-- ;
		}
	}

	i = 0 ;
	for (auto it = m.begin() ; it != m.end() ; it++, i++)
	{
		it->second /= 2 ;
		if (it->second)
		{
			ans.append (string (it->second, it->first)) ;
			save.push_back (it->first) ;
		}
	}

	if (oddcnt)
		ans.push_back (oddch) ;

	i = 0 ;
	for (int j = (int)save.length() - 1 ; j >= 0 ; j--)
		ans.append (string (m[save[j]], save[j])) ;
	
	cout << ans << "\n" ;

	return 0 ;
}
