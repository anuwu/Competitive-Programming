void binInsert (vector<int> &A, int val)
{
    int l, r, mid ;
    
    l = 0 ;
    r = A.size() - 1 ;
    while (l <= r)
    {
        mid = (l + r)/2 ;
        if (val > A[mid])
            l = mid + 1 ;
        else
            r = mid - 1 ;
    }
    
    A.insert (A.begin() + l, val) ;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) 
{
    int i, j, k ;
    long long hashsum, hashxor, hash, hashmul ;
    bool ana ;
    vector<vector<int>> ans ;
    vector<int> group ;
    
    vector<pair<map<char, int>, pair<int, bool>>> cmaps ;
    map<char, int> charmap ;
    
    unordered_multimap <int, int> m ;
    unordered_multimap <int, int>::iterator it1, it2 ;
    
    for (i = 0 ; i < A.size() ; i++)
    {
        hashsum = 0 ;
        hashxor = 0 ;
        hashmul = 1 ;
        for (j = 0 ; j < A[i].length() ; j++)
        {
            hashsum = hashsum + (long long)A[i][j] ;
            hashxor = hashxor ^ (long long)A[i][j] ;
            hashmul = (hashmul * (long long)A[i][j]) % 1000000007 ;
        }
        hash = ((hashsum + hashxor) * 99999) % 1000000007 ;
        //hash = hashmul ;
        m.insert (make_pair ((int)hash, i)) ;
    }

    ans.clear () ;
    for (it1 = m.begin () ; it1 != m.end() ; )
    {
        group.clear () ;
        cmaps.clear () ;
        charmap.clear () ;
        if (m.count (it1->first) == 1)       // If number of words in a bin is 1
        {
            ans.push_back (vector<int> (1, it1->second+1)) ;
            it1++ ;
            continue ;
        }
        
        // Character map of first word of bin
        for (i = 0 ; i < A[it1->second].length() ; i++)
        {
            if (charmap.find (A[it1->second][i]) == charmap.end ())
                charmap[A[it1->second][i]] = 1 ;
            else
                charmap[A[it1->second][i]]++ ;
        }
        cmaps.push_back (make_pair (charmap, make_pair (it1->second, false))) ;     // Inserting first character map into list of charmaps
        ans.push_back (vector<int> (1, it1->second + 1)) ;
            
        it2 = it1 ;
        advance (it2, 1) ;
        while (it2 != m.end() && it2->first == it1->first)
        {
            // Creating character maps of others words in the bin
            charmap.clear () ;
            for (j = 0 ; j < A[it2->second].length() ; j++)
            {
                if (charmap.find (A[it2->second][j]) == charmap.end())
                    charmap [A[it2->second][j]] = 1 ;
                else
                    charmap [A[it2->second][j]]++ ;
            }
            
            // Going over all the maps
            for (j = 0 ; j < cmaps.size() ; j++)
            {
                if (cmaps[j].first.size() == charmap.size ())
                {
                    if (equal (cmaps[j].first.begin(), cmaps[j].first.end(), charmap.begin()))
                    {
                        binInsert (ans[ans.size() - cmaps.size() + j], it2->second + 1) ;
                        cmaps[j].second.second = true ;
                    }
                    else
                    {
                        cmaps.push_back (make_pair (charmap, make_pair (it2->second, false))) ;
                        ans.push_back (vector<int> (1, it2->second + 1)) ;
                    }
                }
                else
                {
                    cmaps.push_back (make_pair (charmap, make_pair (it2->second, false))) ;
                    ans.push_back (vector<int> (1, it2->second + 1)) ;
                }
            }

            it2++ ;
        }
        it1 = it2 ;
    }
    
    return ans ;    
}
