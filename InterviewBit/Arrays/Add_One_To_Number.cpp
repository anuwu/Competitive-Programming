vector<int> Solution::plusOne(vector<int> &A) 
{
    int i ;
    bool carry = false ;
   
    if (A.size () == 0)
    {
        vector<int> ans ;
        ans.push_back (1) ;
        return ans ;
    }
    
    i = -1 ;
    do
    {
        if (!A[i + 1])
            i++ ;
        else
            break ;
    } while (i < A.size () - 1) ;
    
    if (i != -1)
        A.erase (A.begin(), A.begin() + i + 1) ;
    
    if (A.size () == 0)
    {
        vector<int> ans ;
        ans.push_back (1) ;
        return ans ;
    }
    
    i = A.size () - 1 ;
    do
    {
        if (A[i] == 9)
        {
            A[i] = 0 ;
            carry = true ;
        }
        else
        {
            A[i] += 1 ;
            carry = false ;
        }
        i-- ;
    } while (i >= 0 && carry) ;
    
    if (i == -1 && carry)
        A.insert (A.begin(), 1) ;
        
    return A ;
}
