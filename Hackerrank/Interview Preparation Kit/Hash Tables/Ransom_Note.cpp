
vector<string> split_string(string);

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) 
{
    int i, M = magazine.size(), N = note.size() ;
    unordered_map<string,int> m ;
    unordered_map<string,int>::iterator it ;

    for (i = 0 ; i < N ; i++)
    {
        if (m.find(note[i]) == m.end())
            m[note[i]] = 1 ;
        else
            m[note[i]]++ ;
    }

    for (i = 0 ; i < M ; i++)
    {
        it = m.find (magazine[i]) ;
        if (it != m.end())
        {
            it->second-- ;
            if (!it->second)
                m.erase (it) ;
        }
    }

    if (!m.size())
        printf ("Yes\n") ;
    else
        printf ("No\n") ;

}

