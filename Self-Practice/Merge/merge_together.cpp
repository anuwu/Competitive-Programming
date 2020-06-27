#include <iostream>
#include <vector>

using namespace std ;

void merge_end (vector<int> &A, vector<int> &B) 
{
    int i, j, lenA, lenB, k ;
    vector<int> ans ;
    
    lenA = A.size () ;
    lenB = B.size () ;

    ans.reserve (lenA + lenB) ;
    k = 0 ;
    i = 0 ;
    j = 0 ;
    while (i < lenA && j < lenB)
    {
        if (A[i] < B[j])
        {
            ans.push_back (A[i]) ;
            i++ ;
        }
        else
        {
            ans.push_back (B[j]) ;
            j++ ;
        }
        k++ ;
    }
    
    if (i < lenA)
        ans.insert (ans.end(), A.begin() + i, A.end ()) ;
    if (j < lenB)
        ans.insert (ans.end(), B.begin() + j, B.end()) ;
    
    A = ans ;
}

int main ()
{
    vector<int> A, B
    int szA, szB, in, i ;

    cin >> szA ;
    for (i = 0 ; i < szA ; i++)
    {
        cin >> in ;
        A.push_back (in) ;
    }

    cin >> szB ;
    for (i = 0 ; i < szB ; i++)
    {
        cin >> in ;
        B.push_back (in) ;
    }

    merge_end (A, B) ;
    cout << "The merged vector - \n" ;
    for (i = 0 ; i < szA + szB ; i++)
        cout << A[i] << " " ;
    cout << "\n" ;
    
    return 0 ;
}