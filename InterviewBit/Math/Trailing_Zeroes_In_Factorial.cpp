int Solution::trailingZeroes(int A) {
    
       int ans=0;
        int c=5;
        while (A/c>0)
        {
            ans=ans+A/c;
            c*=5;
        }
        
        return ans;
}
