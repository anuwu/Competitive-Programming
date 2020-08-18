string timeConversion(string s) 
{
    if (s[8] == 'P')
    {
        int i, hr ;
        hr = stoi (s.substr(0, 2)) + 12 ;
        string hrstr = to_string (hr) ;

        if (hr < 24)
            for (i = 0 ; i < (int)hrstr.length() ; i++)
                s[i] = hrstr[i] ;
    }

    return s.substr (0, 8) ;
}
