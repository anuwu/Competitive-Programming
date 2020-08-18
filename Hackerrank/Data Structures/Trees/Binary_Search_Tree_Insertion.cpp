Node * insert(Node * root, int data) 
{
    if (!root)
    {
        root = (Node *) malloc (sizeof (Node)) ;
        root->data = data ;
        root->left = NULL ;
        root->right = NULL ;

        return root ;
    }

    if (data < root->data)
    {
        if (root->left)
            insert (root->left, data) ;
        else
        {
            root->left = (Node *) malloc (sizeof (Node)) ;
            root->left->data = data ;
            root->left->left = NULL ;
            root->left->right = NULL ;
        }
    }
    else
    {
        if (root->right)
            insert (root->right, data) ;
        else
        {
            root->right = (Node *) malloc (sizeof (Node)) ;
            root->right->data = data ;
            root->right->left = NULL ;
            root->right->right = NULL ;
        }
    }


    return root;
}
