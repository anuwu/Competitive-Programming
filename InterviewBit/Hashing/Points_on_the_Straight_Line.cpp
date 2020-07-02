#include <algorithm>
#include <functional>
typedef pair<int,int> point ;
typedef pair<int,int> fraction ; 
typedef pair<fraction,fraction> line ;

struct hash_pair 
{ 
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2> &pair) const
    {
        return (*this)(pair.first) ^ (*this)(pair.second);
    }

    template <class T>
    size_t operator() (const T &v) const
    {
        return hash<T>()(v);
    }
};

fraction getFrac (int num, int den)
{
    fraction frac ;
    bool sign ;
    int gcd ;
    
    if (num * den > 0)
        sign = false ;
    else
        sign = true ;
        
    num = (num < 0) ? -num : num ;
    den = (den < 0) ? -den : den ;
    gcd = __gcd (num, den) ;
    num /= gcd ;
    den /= gcd ;
    frac = make_pair (sign ? -num : num, den) ;
    
    return frac ;
}

line getLine (point p1, point p2)
{
    int xdiff, ydiff, intnum, intden ;
    bool sign ;
    fraction slope, intrcpt ;
    
    ydiff = p2.second - p1.second ;
    xdiff = p2.first - p1.first ;
    if (xdiff == 0)
    {
        slope = make_pair (INT_MAX, 0) ;
        intrcpt = make_pair (p1.first, 0) ;
    }
    else
    {
        if (ydiff == 0)
        {
            slope = make_pair (0, 0) ;
            intrcpt = make_pair (p1.second, 1) ;
        }
        else
        {
            slope = getFrac (ydiff, xdiff) ;
            
            intnum = p1.second*p2.first - p1.first*p2.second ;
            intden = p2.first - p1.first ;
            intrcpt = getFrac (intnum, intden) ;
        }
    }
    
    return make_pair (slope, intrcpt) ;
}

int Solution::maxPoints(vector<int> &A, vector<int> &B) 
{
    int i, N, M, ydiff, xdiff, maxpoints, linepoints;
    unordered_map<point, int, hash_pair> points ;
    unordered_map<point, int, hash_pair>::iterator it1, it2 ;
    unordered_map<line, pair<int, int>, hash_pair> lines ;
    point p1, p2 ;
    line l ;
    
    N = A.size() ;
    for (i = 0 ; i < N ; i++)
    {
        p1 = make_pair (A[i], B[i]) ;
        if (points.find (p1) == points.end ())
            points[p1] = 1 ;
        else
            points[p1]++ ;
    }
    
    if (points.size () == 1)
        return points.begin()->second ;

    i = 0 ;
    linepoints = 0 ;
    maxpoints = 0 ;
    M = points.size() ;
    for (it1 = points.begin(), i = 0 ; it1 != points.end() ; it1++, i++)
    {
        p1 = it1->first ;
        auto it2 = it1 ;
        advance (it2, 1) ;
        for ( ; it2 != points.end() ; it2++)
        {
            p2 = it2->first ;
            l = getLine (p1, p2) ;
            auto itf = lines.find (l) ;
            
            if (itf == lines.end())
            {
                linepoints = points[p1] + points[p2] ;
                lines[l] = make_pair (i, points[p1] + points[p2]) ;
            }
            else if (itf->second.first == i)
            {
                linepoints = itf->second.second + points[p2] ;
                itf->second.second = linepoints ;
            }
            
            if (linepoints > maxpoints)
                maxpoints = linepoints ;
        }
    }
    
    return maxpoints ;
}
