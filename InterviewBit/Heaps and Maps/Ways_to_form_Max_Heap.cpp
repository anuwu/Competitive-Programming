#define MOD 1000000007

vector<vector<long long>> nCr ;
vector<long long> heaps ;

void init (int A)
{
    heaps.clear () ;
    nCr.clear () ;    
        
    int n, r ;
    nCr = vector<vector<long long>> (A+1, vector<long long> (A+1, 0)) ;
    heaps = vector<long long> (A+1, -1) ;
    
    for (n = 0 ; n <= A ; n++)
    {
        nCr[n][0] = 0 ;
        nCr[n][1] = n ;
    }
    
    for (n = 3 ; n <= A ; n++)
    {
        for (r = 2 ; r <= n/2 ; r++)
            nCr[n][r] = (nCr[n-1][r > (n-1)/2 ? n-1-r : r] + nCr[n-1][r-1 > (n-1)/2 ? n-r : r-1]) % MOD ;
    }

    heaps[0] = heaps[1] = heaps[2] = 1 ;
    heaps[3] = 2 ;
    heaps[4] = 3 ;
}

int getLeft (int n)
{
    int h, penul, lasthalf, last ;
    
    h = log(n)/log(2) ;
    lasthalf = 1 << (h-1) ;         // 2^(h-1)
    penul = (lasthalf << 1) - 1 ;   // 2^h - 1
    last = n - penul ;
    if (last >= lasthalf)
        return penul ;
        
    return lasthalf - 1 + last ;
    
}

long long noHeaps (int n)
{
    if (heaps[n] != -1)
        return heaps[n] ;
        
    int left, right ;
    left = getLeft (n) ;
    right = n - left - 1 ;
    
    return (((nCr[n-1][left > (n-1)/2 ? n-left-1 : left] * noHeaps (left)) % MOD) * noHeaps (right)) % MOD ;
}

int Solution::solve(int A) 
{
    if (A <= 2)
        return 1 ;
    else if (A <= 4)
        return A-1 ;
        
    init (A) ;
    return noHeaps (A) ;
}

