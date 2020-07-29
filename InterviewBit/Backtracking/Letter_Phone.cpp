
map<char,vector<char>> digmap ;

void phone (int ind, string str, string &A, vector<string> &ans)
{
    if (ind == A.length ())
    {
        ans.push_back (str) ;
        return ;
    }
    
    char ch = A[ind] ;
    for (int i = 0 ; i < digmap[ch].size() ; i++)
    {
        str.push_back (digmap[ch][i]) ;
        phone (ind+1, str, A, ans) ;
        str.erase (str.length() - 1, 1) ;
    }
    
}

vector<string> Solution::letterCombinations(string A) 
{
    digmap.clear () ;
    
    vector<char> mapvec ;
    vector<string> ans ;
    string str ;
    
    mapvec.push_back ('0') ;
    digmap['0'] = mapvec ;
    
    mapvec.clear () ;
    mapvec.push_back ('1') ;
    digmap['1'] = mapvec ;
    
    mapvec.clear () ;
    mapvec.push_back ('a') ;
    mapvec.push_back ('b') ;
    mapvec.push_back ('c') ;
    digmap['2'] = mapvec ;
    
    mapvec.clear () ;
    mapvec.push_back ('d') ;
    mapvec.push_back ('e') ;
    mapvec.push_back ('f') ;
    digmap['3'] = mapvec ;
    
    mapvec.clear () ;
    mapvec.push_back ('g') ;
    mapvec.push_back ('h') ;
    mapvec.push_back ('i') ;
    digmap['4'] = mapvec ;
    
    mapvec.clear () ;
    mapvec.push_back ('j') ;
    mapvec.push_back ('k') ;
    mapvec.push_back ('l') ;
    digmap['5'] = mapvec ;
    
    mapvec.clear () ;
    mapvec.push_back ('m') ;
    mapvec.push_back ('n') ;
    mapvec.push_back ('o') ;
    digmap['6'] = mapvec ;
    
    mapvec.clear () ;
    mapvec.push_back ('p') ;
    mapvec.push_back ('q') ;
    mapvec.push_back ('r') ;
    mapvec.push_back ('s') ;
    digmap['7'] = mapvec ;

    mapvec.clear () ;
    mapvec.push_back ('t') ;
    mapvec.push_back ('u') ;
    mapvec.push_back ('v') ;
    digmap['8'] = mapvec ;
    
    mapvec.clear () ;
    mapvec.push_back ('w') ;
    mapvec.push_back ('x') ;
    mapvec.push_back ('y') ;
    mapvec.push_back ('z') ;
    digmap['9'] = mapvec ;
    
    phone (0, str, A, ans) ;
    return ans ;
}

