Node* helper (Node *root, int K, int *smallCnt)
{
    if (root == NULL)
        return NULL ;

    Node *leftres ;
    leftres = helper (root->left, K, smallCnt) ;
        
    if (leftres == NULL)
    {
        *smallCnt += 1 ;
        if (*smallCnt == K)
            return root ;
        else
            return helper (root->right, K, smallCnt) ;
    }
    else
        return leftres ;
}

int KthSmallestElement(Node *root, int K)
{
    int smallCnt = 0 ;
    Node *res ;
    res = helper (root, K , &smallCnt) ;
    
    if (res)
        return res->data ;
    else
        return -1 ;
}
