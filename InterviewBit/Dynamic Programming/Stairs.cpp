int Solution::climbStairs(int A) 
{
    if (A == 0 || A == 1)
        return 1 ;
        
    if (A == 2)
        return 2 ;
        
    int l, ll, ans ;
    ll = 1 ;
    l = 2 ;
    
    for (int i = 3 ; i <= A ; i++)
    {
        ans = ll + l ;
        ll = l ;
        l = ans ;
    }
    
    return ans ;
}
