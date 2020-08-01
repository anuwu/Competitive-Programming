class Solution {
public:
    
    int subtreeSums (TreeNode *root, unordered_map<int,int> &freqs)
    {
        if (!root)
            return 0 ;
        
        int mysum, sumLeft, sumRight ;
        sumLeft = subtreeSums (root->left, freqs) ;
        sumRight = subtreeSums (root->right, freqs) ;
        
        mysum = sumLeft + sumRight + root->val ;
        if (freqs.find (mysum) == freqs.end ())
            freqs[mysum] = 1 ;
        else
            freqs[mysum]++ ;
        
        return mysum ;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {   
        int maxFreq ;
        vector<int> freqvec ;
        unordered_map<int,int> freqs ;
        unordered_map<int,int>::iterator it ;
        
        if (!root)
            return freqvec ;
        
        subtreeSums (root, freqs) ;
        it = freqs.begin () ;
        maxFreq = it->second ;
        freqvec.push_back (it->first) ;
        
        for (++it ; it != freqs.end() ; it++)
        {
            if (it->second > maxFreq)
            {
                maxFreq = it->second ;
                freqvec.clear () ;
                freqvec.push_back (it->first) ;
            }
            else if (it->second == maxFreq)
                freqvec.push_back (it->first) ;
        }
        
        return freqvec ;
    }
};

