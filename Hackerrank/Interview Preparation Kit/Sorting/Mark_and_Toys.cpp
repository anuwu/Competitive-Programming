int maximumToys(vector<int> prices, int k) 
{
    int i, cnt, N = prices.size() ;
    sort (prices.begin(), prices.end()) ;

    cnt = 0 ;
    i = 0 ;
    while (i < N && k > 0)
    {
        if (k - prices[i] >= 0)
        {
            k -= prices[i] ;
            cnt++ ;
        }
        else
            break ;

        i++ ;
    }

    return cnt ;
}

