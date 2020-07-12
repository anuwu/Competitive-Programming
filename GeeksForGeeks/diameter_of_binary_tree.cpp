int diam (Node* root, int* height)
{
    if (!root)
    {
        *height = 0 ;
        return 0 ;
    }
    
    int heightLeft, heightRight ;
    int leftDiam, rightDiam ;
    
    leftDiam = diam (root->left, &heightLeft) ;
    rightDiam = diam (root->right, &heightRight) ;
    
    *height = max (heightLeft, heightRight) + 1 ;
    
    return max (heightLeft + heightRight + 1, max (leftDiam, rightDiam)) ;
}

int diameter (Node* node) 
{
    int height ;
    return diam (node, &height) ;
}

