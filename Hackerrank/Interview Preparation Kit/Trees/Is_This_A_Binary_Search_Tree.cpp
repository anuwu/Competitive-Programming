bool check (Node *root, int liml, int limr)
{
    if (!root)
        return true ;
    
    return liml < root->data && root->data < limr && check (root->left, liml, root->data) && check (root->right, root->data, limr) ;
}
    

bool checkBST(Node* root) 
{
    return check (root, INT_MIN, INT_MAX) ;
}
